class Solution {
public:
    bool checkPerfectNumber(int num) {
        int i;
        if((num == 1) || (num <= 0))
            return false;
        int sum=0;
        for(i=1;i*i<=num;i++){
            if(num % i == 0){
                sum += i;
                //include 1 & exclude 28(or n) 
                if(num/i!=num){
                    sum+=num/i;
                }
            }  
        }
        if(num==sum)
            return true;
        else
        return false;
    }
};
