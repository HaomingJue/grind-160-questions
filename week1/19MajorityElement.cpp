#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, res = INT_MIN;
        for (int num : nums) {
            if (res == INT_MIN) {
                res = num;
                count = 1;
            }
            else if (num == res) {
                count++;
            }
            else {
                count--;
                if (count == -1) {
                    count = 0;
                    res = num;
                }
            }
        }
        return res;
    }
};