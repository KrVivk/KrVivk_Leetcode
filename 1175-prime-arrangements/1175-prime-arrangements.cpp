class Solution {
public:
    int mod = 1e9 + 7;
    int fac(int n){
        int res = 1;
        for(int i = 2; i <= n; i++){
            res = res % mod;
            res = ((long long) res * i )% mod;
        }
        return res % mod;
    }
    int numPrimeArrangements(int n) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for(int i = 2; i * i <= n; i++){
            if(prime[i]){
                for(int j = i * i; j <= n; j += i){
                    prime[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i <= n; i++){
            if(prime[i]) count++;
        }
        return ((long long) fac(n - count) % mod * fac(count) % mod) % mod;
    }
};