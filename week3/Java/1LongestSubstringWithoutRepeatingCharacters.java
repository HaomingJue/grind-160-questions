class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> memo = new HashMap<>();
        int i = 0, j = 0;
        int res = 0;
        while (j < s.length()) {
            if (!memo.containsKey(s.charAt(j)) || memo.get(s.charAt(j)) < i) {
                memo.put(s.charAt(j), j);
            }
            else {
                i = memo.get(s.charAt(j)) + 1;
                memo.put(s.charAt(j), j);
            }
            res = Math.max(res, j - i + 1);
            j++;
        }
        return res;
    }
}