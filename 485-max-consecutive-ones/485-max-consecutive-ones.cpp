class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxcount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                count++;
            else{
                maxcount=max(count,maxcount);
                count=0;
            }
        }
        return max(count,maxcount);
    }
};