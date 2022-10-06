class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 1; 
        int x = min(a,b);
        for(int i = 2; i <= x; i++){
            if(a % i == 0 && b % i == 0)
                count++;
        }
        return count;
    }
};