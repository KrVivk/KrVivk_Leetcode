class Solution {
public:
    bool isPowerOfTwo(int n) {
       /* for(int i=0;i<=30;i++)
        {
            int ans=pow(2,i);
            if(ans==n){
                return true;
            }
        }
        return false;*/
        return n > 0 && !(n & n - 1);
    }
};
//checked all powers of 2 in the range of int 2^0 till 2^30 & matched it with n.
