#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (!withInRange(i, s)) {
                i++;
                continue;
            }
            if (!withInRange(j, s)) {
                j--;
                continue;
            }
            if (!equals(i, j, s)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool withInRange(int i, string &s) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            return true;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            return true;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            return true;
        }
        return false;
    }

    bool equals(int i, int j, string &s) {
        if (s[i] >= 'A' && s[i] <='Z') {
            return s[i] == s[j] || s[i] == s[j] - 32;
        }
        if (s[i] >= 'a' && s[i] <='z') {
            return s[i] == s[j] || s[i] == s[j] + 32;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            return s[i] == s[j];
        }
        return false;
    }
};