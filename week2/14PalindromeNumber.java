class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int a = x, n = 0;
        while (a > 0) {
            n++;
            a /= 10;
        }
        for (int i = 1; i <= n / 2; i++) {
            if (extractDigit(x, i) != extractDigit(x, n - i + 1)) {
                return false;
            }
        }
        return true;
    }

    private int extractDigit(int x, int digit) {
        return x % (int)Math.pow(10, digit) / (int)Math.pow(10, digit - 1);
    }
}