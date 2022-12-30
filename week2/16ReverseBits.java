public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int mask = 1, ans = 0;
        for (int i = 0; i < 32; i++) {
            int lastBit = (n >> i) & mask;
            ans = ans | (lastBit << (31 - i));
        }
        return ans;
    }
}