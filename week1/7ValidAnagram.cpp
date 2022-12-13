#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> record(26);
        for (char c : s) {
            record[c - 'a']++;
        }
        for (char c : t) {
            record[c - 'a']--;
        }
        for (int i = 0; i < record.size(); i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }

};