class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
          int n=queries.size(),k=0;

        vector<int>ans(arr.size()),result;
        ans[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            ans[i]=(ans[i-1]^arr[i]);
        }
        while(k<n){
            int i=queries[k][0];
            int j=queries[k][1];
            int a;
           if(i !=0){
               result.push_back(ans[j]^ans[i-1]);
           } 
            else{
                 result.push_back(ans[j]);
            }
            k++;
        }
        return result;
    }
};