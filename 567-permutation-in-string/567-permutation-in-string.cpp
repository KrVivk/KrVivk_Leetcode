class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        int m[26]={0};
        for(char c:s1) 
            m[c-'a']++;
        int i=0,j=0,total_chars=s1.size();
        while(j<s2.size())
        {
            if(m[s2.at(j++) - 'a']-- > 0)
                total_chars--;
            if(total_chars == 0) return true;
            //shifting of window
            if(j - i == s1.size() && m[s2.at(i++) - 'a']++ >= 0)
                total_chars++;
        }
        return false;
    }      
};