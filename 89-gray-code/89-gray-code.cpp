class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans={0,1};
        for(int i=1;i<n;i++){
            auto temp=ans;
            reverse(temp.begin(),temp.end());
            for(auto& v: temp)v+=1<<i;
            ans.insert(ans.end(),temp.begin(),temp.end());
        }
        return ans;
    }
};