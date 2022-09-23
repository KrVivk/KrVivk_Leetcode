class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0,cmd=0;
        for(int num:nums){
            if(count==0){
                cmd=num;
            }
            if(num==cmd) count++;
            else count--;
        }
         return cmd;  
    }
};
//Moore's Voting Algorithm