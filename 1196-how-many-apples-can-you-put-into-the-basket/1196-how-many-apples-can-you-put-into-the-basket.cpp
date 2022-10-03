class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(),weight.end());
		int count=0,sum=0;
		for(auto i:weight){
			sum+=i;
			if(sum<=5000)
				count++;
		}
		return count;
    }
};