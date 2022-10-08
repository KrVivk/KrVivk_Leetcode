class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
         return false;
     int H[126]={0};
     for(int i=0; i<s.length(); i++){
         H[s[i]]++;
     }
     for(int i=0; i<t.length(); i++){
         H[t[i]]--;
     }
     
     for(int i=0; i<126; i++){
         if(H[i]>0){
             return false;
         }
     }
     return true;
    }
};