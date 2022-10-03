class Solution {
public:
    string convertToTitle(int N) {
        string ans="";
        while(N)
        {
            char c = 'A'+ (N-1) % 26;
            ans = ans + c;
            N = (N-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};