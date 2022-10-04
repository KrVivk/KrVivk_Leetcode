class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;
        int ans = 0;
        while (n) {
            n = n & (n-1);
            ans++;
        }
        return ans;
    }
};
// xoring numbers to get a number which has bits set iff we need to flip that bit
// counting set bits in the xored number