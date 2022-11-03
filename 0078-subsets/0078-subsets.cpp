class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int> &nums,int i,int n,vector<int> v){//recursive function
        if(i==n){
            ans.push_back(v);//insert v in answer 
            return;
        }
        rec(nums,i+1,n,v);//element at current index not selected for v
        v.push_back(nums[i]);
        rec(nums,i+1,n,v);//element at current index selected for v
    }
    vector<vector<int>> subsets(vector<int>& nums){
        vector<int> v;
        rec(nums,0,nums.size(),v);
        return ans;
    }
};