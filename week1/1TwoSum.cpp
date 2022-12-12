#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (umap.find(target - nums[i]) == umap.end()) {
                umap[nums[i]] = i;
            }
            else {
                ans.push_back(i);
                ans.push_back(umap[target - nums[i]]);
                return ans;
            }
        }
        return ans;
    }
};