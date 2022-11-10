class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> curr,int k,int n,int sum)
    {
        if(k==0)
        {
            if(sum == n)
            {
                 ans.push_back(curr);
            }
            return;
        }
        if(curr.size()==0)
        {
            for(int i=1;i<=9;++i)
            {
                if(i + sum <=n)
                {
                    vector<int> temp =curr;
                    temp.push_back(i);
                    solve(temp,k-1,n,sum+i);
                }
            }
        }
        else
        {
            for(int i=curr.back()+1;i<=9;++i)
            {
                if(i + sum <=n)
                {
                    vector<int> temp =curr;
                    temp.push_back(i);
                    solve(temp,k-1,n,sum+i);
                }
            }   
        }   
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        solve({},k,n,0);
        return ans;   
    }
};