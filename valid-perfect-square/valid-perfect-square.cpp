class Solution {
public:
    bool isPerfectSquare(int num) {
        long int high=100000;
        long int low=1,sq,mid;
        while(low <= high){
            mid = low + (high-low)/2;
            sq = mid*mid;
            if(sq==num)
                return true;
            else if(sq<num)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};