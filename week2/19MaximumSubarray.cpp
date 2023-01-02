class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int curSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            curSum = curSum > 0 ? curSum + nums[i] : nums[i];
            ans = max(curSum, ans);
        }
        return ans;
    }
};