class Solution {
public:
    int findGCD(vector<int>& numsDivide){
        int result = numsDivide[0];
        for(int i=0;i<numsDivide.size();i++){
            result = gcd(numsDivide[i],result);
        }
        return result;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int result = findGCD(numsDivide);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(result % nums[i]==0)
                return i;
        }
        return -1;
    }
};