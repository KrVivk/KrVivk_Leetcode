class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(),weight.end());
		int apples=0,units=0;
		for(int i=0;i<weight.size() && units+weight[i]<=5000; i++){
			apples++;
			units+=weight[i];
		}
		return apples;
    }
};