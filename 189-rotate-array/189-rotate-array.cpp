class Solution {
public:
void reverse(vector<int>& nums,int i,int j)
{
	 int m,n,temp;
	 for(m=i,n=j ; m<n ; m++,n--)
	 {
		temp=nums[m];
		nums[m]=nums[n];
		nums[n]=temp;
	 }
	
}
void rotate(vector<int>& nums, int k) {
    int i,j;
	k%=nums.size();
    if(k < 0){ 
       k += nums.size();
        }
	reverse(nums,nums.size()-k,nums.size()-1);//reversing array individually 
	reverse(nums,0,nums.size()-k-1);//reversing 2nd time for 
	reverse(nums,0,nums.size()-1);//whole array reversed
        
    }
};













