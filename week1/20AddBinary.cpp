#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        if (a.length() < b.length()) {
            return addBinary(b, a);
        }
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
        for (; j >=0; i--, j--) {
            addBinary(a[i] - '0', b[j] - '0', carry, ans);
        }
        while (i >= 0) {
            addBinary(a[i--] - '0', 0, carry, ans);
        }
        if (carry != 0) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

private:
    void addBinary(int a, int b, int & carry, string& ans) {
        ans += '0' + ((a + b + carry) % 2 );
        carry = (a + b + carry) >= 2 ? 1 : 0;
    }
};