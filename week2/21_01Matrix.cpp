#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return bfs(mat);
    }

private:
    vector<vector<int>> bfs(vector<vector<int>>& mat) {
        vector<vector<int>> res (mat.size(), vector<int> (mat[0].size(), 100000));
        queue<pair<int ,int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }
        int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            int i = cur.first;
            int j = cur.second;
            q.pop();
            for (auto dir : directions) {
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if (i_ >= 0 && j_ >= 0 && i_ < mat.size() && j_ < mat[0].size()) {
                    if (res[i_][j_] > res[i][j] + 1) {
                        res[i_][j_] = res[i][j] + 1;
                        q.push({i_, j_});
                    }
                }
            }
        }
        return res;
    }


    vector<vector<int>> dp(vector<vector<int>> & mat) {
        vector<vector<int>> res (mat.size(), vector<int> (mat[0].size(), 1000000));
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                }
                else {
                    if (i > 0) {
                        res[i][j] = min(res[i][j], res[i - 1][j] + 1);
                    } 
                    if (j > 0) {
                        res[i][j] = min(res[i][j], res[i][j - 1] + 1);
                    }
                }
            }
        }
        for (int i = mat.size() - 1; i >= 0; i--) {
            for (int j = mat[0].size() - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                }
                else {
                    if (i < mat.size() - 1) {
                        res[i][j] = min(res[i][j], res[i + 1][j] + 1);
                    } 
                    if (j < mat[0].size() - 1) {
                        res[i][j] = min(res[i][j], res[i][j + 1] + 1);
                    }
                }
            }
        }
        return res;
    }
};