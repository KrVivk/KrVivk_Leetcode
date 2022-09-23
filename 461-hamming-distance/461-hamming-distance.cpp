class Solution {
public:
    int hammingDistance(int x, int y) {
        long mask =(1L<<31);
        int count =0;
        for(int i=31;i>=0;i--)
        {
            if((mask & x) != (mask&y))
                count++;
            mask>>=1;
        }
        return count;
    }
};
//Read solution & discussion