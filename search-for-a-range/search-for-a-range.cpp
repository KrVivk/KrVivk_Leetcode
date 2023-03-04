class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int n = nums.size() - 1;
        int low = 0, high = n;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(nums[mid] < target) 
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
            else {
                if(mid==0){
                    ans[0] = mid;
                    break;
                }
                else if(nums[mid-1]!=target) {
                    ans[0] = mid;
                    break;
                }
                else
                    high = mid-1;
            }
        }

        low = 0, high = n;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid] < target) 
                low = mid+1;
            else if(nums[mid] > target)
                high = mid-1;
            else {
                if(mid == n){
                    ans[1] = mid;
                    break;
                }
                else if(nums[mid+1]!=target) {
                    ans[1] = mid;
                    break;
                }
                else
                    low = mid+1;
            }
        }
        return ans;
    }
};