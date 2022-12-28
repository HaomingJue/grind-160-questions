class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder sb = new StringBuilder();
        if (strs[0] == null) {
            return "";
        }
        for (int i = 0; i < strs[0].length(); i++) {
            char cur = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (strs[j].length() <= i) {
                    return sb.toString();
                }
                else if (strs[j].charAt(i) != cur) {
                    return sb.toString();
                }
            }
            sb.append(cur);
        }
        return sb.toString();
    }
}