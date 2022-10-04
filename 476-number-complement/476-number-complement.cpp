class Solution {
public:
    int findComplement(int num) {
        long powof2 = 2, temp = num;
        while(temp>>1) {
            temp >>= 1;
            powof2 <<= 1;
        }
        return powof2 - num - 1;
    }
};