#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> memo;
        int res = 0, i = 0, j = 0;
        while (j < s.length()) {
            if (memo.find(s[j]) == memo.end() || memo[s[j]] < i) {
                memo[s[j]] = j;
                res = max(j - i + 1, res);
            }
            else {
                i = memo[s[j]] + 1;
                memo[s[j]] = j;
            }
            j++;
        }
        return res;
    }
};