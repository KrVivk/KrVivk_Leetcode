class Solution {
public:
    int missingNumber(vector<int>& nums) { 
        int expectedXor=0;
        for(int i=0;i<=nums.size();i++){
            expectedXor ^= i;
        }
        int actualXor = 0;
        for(int num:nums){
            actualXor ^= num;
        }
        return expectedXor^actualXor;
        
    }
};
