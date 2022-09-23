class Solution {
public:
    //sliding window problem
    int maxVowels(string s, int k) {
    // your code goes here
	int n;
	n = s.length();
	int ans = INT_MIN,cnt=0;
	for(int i=0;i<k;i++){
			if((s[i] == 'a' || s[i] == 'e' || s[i] == 'i'|| s[i] == 'o' || s[i] == 'u' )){
				cnt++;
			}
		}
		ans=cnt;
		for(int j=k;j<n;j++){
			if((s[j] == 'a' || s[j] == 'e' || s[j] == 'i'|| s[j] == 'o' || s[j] == 'u')){
				cnt++;
			}
			if(s[j-k] == 'a' || s[j-k] == 'e'|| s[j-k] == 'i' || s[j-k] == 'o' || s[j-k] == 'u' ){
                cnt--;
			}
			ans=max(ans,cnt);
		}
		return ans;
	}
};