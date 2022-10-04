class Solution {
public:
    int lengthOfLastWord(string s) { 
        int cnt = 0, flag = 0;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i] != ' ')
            {
                flag = 1; //this warns about the first occurance of the non-space char(i.e starting of the first word)
                cnt++; //this counts the number of the chars in the word
            }
            else if(flag == 1 && s[i] == ' ') //this checks if that the current iteration is not the first space char(i.e some non-space chars are already before this because the flag is 1)
            {
                break;
            }
        }
        return cnt;
    }
};
