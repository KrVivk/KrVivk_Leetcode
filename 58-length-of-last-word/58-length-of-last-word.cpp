class Solution {
public:
    int lengthOfLastWord(string s) { 
        reverse(s.begin(), s.end());
        int cnt = 0, flag = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != ' ')
            {
                flag = 1; 
                cnt++; 
            }
            else if(flag == 1 && s[i] == ' ') 
            {
                break;
            }
        }
        return cnt;
    }
};
