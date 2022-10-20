class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
       int ans = nums[0];
        for (int a: nums)
            ans = gcd(ans, a);
        return ans == 1;
    }
};