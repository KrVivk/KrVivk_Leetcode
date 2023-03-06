class Solution {
public:
    int hammingWeight(uint32_t n) {
        long mask = (1L<<31);
        int count = 0;
        while(mask){
            if(mask & n)
                count++;
            mask >>= 1;
        }
        return count;
    }
};