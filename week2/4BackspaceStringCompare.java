class Solution {
    public boolean backspaceCompare(String s, String t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        while (i >= 0 || j >= 0) {
            i = clearBackSpace(s, i);
            j = clearBackSpace(t, j);
            if (i >= 0 && j >= 0 && s.charAt(i) != t.charAt(j)) {
                return false; 
            }
            if ((i < 0 && j >= 0) || (j < 0 && i >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }

    private int clearBackSpace(String s, int i) {
        int skip = 0;
        while (i >= 0) {
            if (s.charAt(i) == '#') {
                skip++;
                i--;
            }
            else if (skip > 0) {
                skip--;
                i--;
            }
            else {
                break;
            }
        }
        return i;
    }
}