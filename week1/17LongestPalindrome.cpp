#include <vector> 
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> vec(128);
        for (char c : s) {
            vec[c]++;
        }
        bool flag = true;
        int ans = 0;
        for (int i = 0; i < 128; i++) {
            if (vec[i] % 2 == 1) {
                if (flag) {
                    flag = false;
                    ans += 1;
                }
                vec[i] -= 1;
            }
            ans += vec[i];
        }
        return ans;
    }
};