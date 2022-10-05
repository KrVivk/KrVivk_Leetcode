class Solution {
public:
    string toHex(int num) {
         if(num == 0) 
            return to_string(0);
        unsigned int n = num;
        string digits="0123456789abcdef";
        string ans="";
        while(n > 0){
            int rem = n % 16;
            ans+=digits[rem];
            n /=16;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};