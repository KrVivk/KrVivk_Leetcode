class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            unsigned temp=a&b; //int mein left shift krne seh limit seh bahar ho jarha hai of larger value 
            a=a^b;
            b=temp<<1;
        }
        return a;
    }
};