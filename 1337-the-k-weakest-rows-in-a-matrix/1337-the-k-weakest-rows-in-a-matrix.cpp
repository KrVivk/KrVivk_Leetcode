class Solution {
public:
    int binary(vector<int> &mat)
    {
        int low = 0;
        int ans = -1;
        int high = mat.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(mat[mid]==1)
            {
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
      
        return ans-0+1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ans;
        for(int i=0;i<mat.size();i++)
        {
            int res=binary(mat[i]);
            ans.push_back({res,i});
        }
        sort(ans.begin(),ans.end());
        vector<int>ret;
        for(int i=0;i<k;i++)
        {
            ret.push_back(ans[i].second);
        }
        return ret;
    }
};

        