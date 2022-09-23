class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int overall_xor=0;
        for(int i=0;i<nums.size();i++){
            overall_xor^=nums[i];
        }
        int leastsetBit=1;
        while(!(leastsetBit & overall_xor))
        {
            leastsetBit<<=1;
        }
        int val1=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&leastsetBit)
                val1^=nums[i];
        }
        int val2 = val1^overall_xor;
        return {val1,val2};
    }
};