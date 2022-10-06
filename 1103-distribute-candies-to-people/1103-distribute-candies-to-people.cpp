class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int val=1,idx=0;
        vector<int> ans(num_people,0);
        while(candies){
            ans[idx++]+=val;
            candies-=val++;
            if(idx==num_people) 
                idx=0;
            if(val>candies) 
                val=candies;
        }
        return ans;
    }
};