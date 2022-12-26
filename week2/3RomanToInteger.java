class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> valueMap = new HashMap<>();
        valueMap.put('I', 1);
        valueMap.put('V', 5);
        valueMap.put('X', 10);
        valueMap.put('L', 50);
        valueMap.put('C', 100);
        valueMap.put('D', 500);
        valueMap.put('M', 1000);
        char last = ' ';
        int ans = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if ((last == 'V' || last == 'X') && s.charAt(i) == 'I') {
                ans -= 1;
            }
            else if ((last == 'L' || last == 'C') && s.charAt(i) == 'X') {
                ans -= 10;
            }
            else if ( (last == 'D' || last == 'M') && s.charAt(i) == 'C') {
                ans -= 100;
            }
            else {
                ans += valueMap.get(s.charAt(i));
            }
            last = s.charAt(i);
        }
        return ans;
    }
}