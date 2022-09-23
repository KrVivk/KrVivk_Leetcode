class Solution {
public:
    int romanToInt(string s) {
       map<char, int> mp{{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M',1000}};
        int result = mp[s.length()-1];
        for(int i = s.length()-1; i >= 0; i--) {
            if(mp[s[i]]<mp[s[i+1]]){
                result-=mp[s[i]];
            }
            else {
                result+=mp[s[i]];
            }
        } 
        return result;
    }
};