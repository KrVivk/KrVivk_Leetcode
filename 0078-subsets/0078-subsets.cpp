class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        
        vector<vector<int>> ans;
        
        for(int mask = 0; mask < (1<<len); mask++){
               vector<int> subset;
             for(int i=0; i<len; i++){
                  if((mask & 1<<i)){
                      subset.push_back(nums[i]);   
                  }
             }
                ans.push_back(subset);
        }
        
           return ans;
    }
};