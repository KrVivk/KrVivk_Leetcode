class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            int element=nums[i];
             if(element>=1 && element<=n)
             {
                int place = element -1;
                if(nums[place]!=element)
                 {
                   swap(nums[place],nums[i]);
                   i--;
                 }
             }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
};