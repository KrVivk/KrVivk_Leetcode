
class Solution {
    vector<int> div(int n) {
        vector<int> v = {INT_MAX, 0};
        for(int i=1; i<=sqrt(n); i++) {
            if(n % i == 0) {
                vector<int> v1 = {i, n / i};
                if(abs(v[0] - v[1]) > abs(v1[0] - v1[1])) v = v1;
            }
        }
        return v;
    }
public:
    vector<int> closestDivisors(int num) {
        vector<int> a = div(num + 1), b = div(num + 2);
        return abs(a[0] - a[1]) < abs(b[0] - b[1]) ? a : b;
    }
};        
