class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int d,s=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            d=nums[0]%10;
            s+=d;
            nums[0]/=10;
        }
        if(s%2==0)
            return 1;
        else 
            return 0;
    }
};