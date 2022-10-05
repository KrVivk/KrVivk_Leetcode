class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag=0;
        if(n&1==1)
            flag=1;
        n>>=1;
        while(n){
            if(n&1==1){
                if(flag==1)
                    return false;
            }
            else{
                if(flag==0)
                    return false;
            }
            flag=(n&1);
            n>>=1;
        }
        return true;
    }
};