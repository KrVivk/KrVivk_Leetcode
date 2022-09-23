class Solution {
public:
    char findTheDifference(string s, string t) {
        char c = 0;
        for(char Char_s : s) c ^= Char_s;
        for(char Char_t : t) c ^= Char_t;
        return c; 
    }
};