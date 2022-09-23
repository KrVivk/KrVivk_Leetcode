
class Solution {
public:
    long long getApSum(long long a, long long n, long long d) {
        return  ((2*a+(n-1)*d)*n)/2;
    }
    long long minimalKSum(vector<int>& nums, int k) {
        long long res=0;
        
        // To use first element also. Like if nums start with 5 than we can add [1,2,3,4]
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        
        // Keep adding till k
        for(int i=0;i<nums.size()-1 && k>0;++i) {
            
            // Get the length of AP which can be added.
            int n = nums[i+1]-nums[i]-1;
            
            // If we can't add any element, for example [12,12] or [11,12].
            if(n<=0) continue;
            
            // If we have option to add much more than needed. For example [1,12] and k is 5. So we need only 5 element to add.
            if(k<n) n=k;
            k-= n;
            
            // Get the sum of n AP elements who's first element is nums[i]+1 and keep difference of 1.
            res += getApSum(nums[i]+1, n, 1);
        }
        
        // If still we k to add element than add continuous k element from nums.back()+1.
        // For example : nums[1,2] and k=5 So we need add [3,4,5,6,7].
        if(k>0) {
            res+= getApSum(nums.back()+1, k, 1);
        }
        return res;
    }
};        
    
