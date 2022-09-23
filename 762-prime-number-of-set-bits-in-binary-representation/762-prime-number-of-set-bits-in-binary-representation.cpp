class Solution {
public:
    bool isPrime(int n){
        if(n==2||n==3||n==5 ||n==7||n==11||n==13||n==17||n==19)
            return true;
        return false;
    }
    int setCount(int n){
        int count=0;
        while(n>0){
            n=n&(n-1);
            count++;
        }
        return count;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int count=setCount(i);
            if(isPrime(count))
                ans++;
            
        }
        return ans;
    }
};