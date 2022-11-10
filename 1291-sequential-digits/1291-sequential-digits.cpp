class Solution {
public:
    vector<int> ans;
    void DFS(int i,int nums,int low,int high){
        if(nums>=low && nums<=high)
            ans.push_back(nums);
        if(nums>high || i>9)
            return;
        DFS(i+1,nums*10+i,low,high);
    }

    vector<int> sequentialDigits(int low, int high) {
        for(int i=1;i<=9;i++)
            DFS(i,0,low,high);
        sort(ans.begin(),ans.end());
        return ans;
    }
};