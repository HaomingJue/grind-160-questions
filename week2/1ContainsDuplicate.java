class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> memo = new HashSet<>();
        for (int num : nums) {
            if (memo.contains(num)) {
                return true;
            }
            memo.add(num);
        }
        return false;
    }
}