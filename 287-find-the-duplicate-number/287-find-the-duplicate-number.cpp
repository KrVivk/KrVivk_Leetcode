class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int repnum = 0;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size()-1; i++)
        {
			// if two consecutive elements are equal
			// you have find a duplicate
			// break the loop
            if(nums[i] == nums[i+1])
            {
                repnum = nums[i];
                break;
            }
        }
        // return duplicate value
        return repnum;
    }
};
//Brute Force method