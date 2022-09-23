typedef long long int ll;
class Solution {
public:
    int minimumOneBitOperations(int n) {
        vector<ll> f(31);
        f[0] = 1;
        for (int j = 1; j < 31; j ++) f[j] = f[j-1]*2 + 1;
        
        int ans = 0;
        int plus = 1;
        
        for (int j = 30; j >= 0; j --) {
            bool is_jth_bit_set = ((1 << j)&n) != 0;
            if (!is_jth_bit_set) continue;
                
            if (plus) ans += f[j];
            else ans -= f[j];
            plus ^= 1;
        }
        
        return ans;
    }
};