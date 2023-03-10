class Solution {
public:
    double ans(double x, long long n){
        if(n==0)
            return 1.0;
        double y = ans(x,n/2);
        if(n%2==0)
            return y*y;
        else
            return y*y*x;
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return ans(x, N);
    }
};