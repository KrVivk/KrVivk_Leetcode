class Solution {
public:
    int xor_Of_all_elements(vector<int> &nums){
        int x=0;
        for(auto it:nums)
            x^=it;
        return x;
    }
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int x1=xor_Of_all_elements(nums1);
        int x2=xor_Of_all_elements(nums2);
        int n=nums1.size(),m=nums2.size();
        if(n%2==0 && m%2==0)
            return 0;
        else if(n%2==0 && m%2!=0)
            return x1;
        else if(n%2!=0 && m%2==0)
            return x2;
        else
            return x1^x2;
    }
};