class Solution {
public:
     void permute(vector<int>& nums,vector<vector<int>> &ans,int i){
        if(i==nums.size()-1){
            ans.push_back(nums);
            return;
        }
        int temp[20] = {0};
        for(int j=i;j<nums.size();j++){
            if(temp[(nums[j])+10] == 0){
                swap(nums[i],nums[j]);
                permute(nums,ans,i+1);
                swap(nums[i],nums[j]);
            }
            temp[nums[j]+10]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums,ans, 0);
        return ans;
    }
};