// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
using namespace std;

bool isBadVersion(int m) {return false;}


class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, h = n;
        while (l < h) {
            int m = (h - l) / 2 + l;;
            if (isBadVersion(m)) h = m;
            else l = m + 1;
        }
        return l;
    }
};