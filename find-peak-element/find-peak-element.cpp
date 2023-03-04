class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        if(low == high) 
            return low;
        while(low<=high) {
            int mid = (low+high)/2;
            // both edge case lies at the edges i.e at 0 & n-1
            if(mid==0) { // 1st edge case
                if(nums[mid]>nums[mid+1])
                return mid;
                else
                    low=mid+1;
            }
            else if(mid==n-1) {//2nd edge case 
                if(nums[mid]>nums[mid-1])
                    return mid;
                else
                    high=mid-1;
            }
            //When mid is our answer
            else if(mid>0 && mid<n-1 && nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
                return mid;
            else if(mid>0 && nums[mid]<nums[mid-1])
                high=mid-1;
            else if(mid<n-1 && nums[mid]<nums[mid+1])
                low=mid+1;
        }
        return -1;
    }
};