class Solution {
public:
    vector<int> sortByBits(vector<int>& arr){
        vector<pair<int, int>> bits;
        vector<int> ans;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int cnt = 0;
            int x = arr[i];
            while(x){
                x &= (x-1);
                cnt++;
            }
            bits.push_back({cnt, arr[i]});
        }
        sort(bits.begin(), bits.end());
        for(int i = 0; i < n; i++){
            ans.push_back(bits[i].second);
        }
        return ans;
    }
    
};
