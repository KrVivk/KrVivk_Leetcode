class Solution {
    typedef long long ll;
public:
    ll lcm(ll a,ll b){
        return (a*b)/gcd(a,b);
    }
    ll func(ll x,ll a,ll b,ll c){
        return(x/a + x/b + x/c - x/lcm(a,b) - x/lcm(b,c) - x/lcm(a,c) + x/lcm(a,lcm(b,c)));
        
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll high=2e9,low=0;
        while(low<high-1){
            ll mid = (low+high)/2;
            if(func(mid,a,b,c)<n) 
                low=mid;
            else 
                high = mid;
        }
        return high;
    }
};
