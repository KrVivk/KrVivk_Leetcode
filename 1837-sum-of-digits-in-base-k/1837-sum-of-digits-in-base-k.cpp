class Solution {
public:
    int sumBase(int n, int k) {
        int ans=0;
        while(n>=k){
            int x=n%k;
            ans*=10;
            ans+=x;
            n/=k;
        }
        if(n>0){
            ans*=10;
            ans+=n;
        }
        int total=0;
        while(ans){
            total+=(ans%10);
            ans/=10;
        }
        return total;
    }
};