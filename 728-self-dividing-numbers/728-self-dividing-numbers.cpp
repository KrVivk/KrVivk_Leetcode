class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(selfdividing(i))
                ans.push_back(i);
        }
        return ans;
    }
    bool selfdividing(int n){
        int x=n;
        while(x>0){
            int digit = x%10;
            x/=10;
            if(digit==0||(n % digit))
                return false;
        }
        return true;   
    }
};