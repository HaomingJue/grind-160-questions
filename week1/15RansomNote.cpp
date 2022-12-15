#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vec(26);
        for (char m : magazine) {
            vec[m - 'a']++;
        }
        for (char r : ransomNote) {
            vec[r - 'a']--;
            if (vec[r - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};