class Solution {
    public int missingNumber(int[] nums) {
        int mask = nums.length;
        for (int i = 0; i < nums.length; i++) {
            mask = mask ^ (i ^ nums[i]);
        }
        return mask;
    }
}