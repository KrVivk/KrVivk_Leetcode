class Solution {
public:
    bool find_if_kthbit_set(int k,unsigned int n){
        if(((1 << (k-1))&n)!=0)
            return true;
        return false;
    }
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans=0;
        for(int i=1;i<=32;i++){
            if(find_if_kthbit_set(i,n)){
                ans = 1<<(32-i) | ans;
            }
        }
        return ans;
    }
};