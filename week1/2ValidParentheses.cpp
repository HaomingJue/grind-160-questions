#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> record;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '[' || c == '{' || c == '(') {
                record.push(c);
            }
            else if (c == ']' || c == ')' || c == '}') {
                if (record.empty() || helper[c] != record.top()) {
                    return false;
                }
                record.pop();
            }
        }
        return record.empty();
    }

private:
    unordered_map<char, char> helper = {{']', '['}, {'}', '{'}, {')','('}};
};