class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
         int ans = 0,sum,cnt;
        for(int i=0;i<nums.size();i++) {
            sum = 0;
            cnt = 0;
            for(int j=1; j*j<=nums[i]; j++) {
                if (nums[i]%j==0) {
                    if (nums[i]/j == j) {
                        sum += j;
                        cnt++;
                    } else {
                        sum += j + (nums[i]/j);
                        cnt += 2;
                    }
                }
            }
            if (cnt == 4) ans += sum;
        }
        return ans;
    }
};