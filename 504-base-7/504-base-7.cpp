class Solution {
public:
    string convertToBase7(int num) {
        int res=0, digit=1;
    while(num!=0){    
        res+=digit*(num%7);
        num/=7;
        digit*=10;
    }
    return to_string(res);
    }
};