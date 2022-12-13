#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }

private:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int original) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != original || image[sr][sc] == color) {
            return;
        }
        image[sr][sc] = color;
        dfs(image, sr + 0, sc + 1, color, original);
        dfs(image, sr + 1, sc + 0, color, original);
        dfs(image, sr + 0, sc - 1, color, original);
        dfs(image, sr - 1, sc + 0, color, original);
    }
};