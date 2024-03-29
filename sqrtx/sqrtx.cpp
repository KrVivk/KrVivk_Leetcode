class Solution {
public:
    int mySqrt(int x) {
        long long int low = 0,high = x,ans=0,mid;
        while(low<=high){
            mid = (low+high)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid<x){
                low=mid+1;
                ans = mid;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};