class Solution {
public:
    int countEven(int num) {
        int sum=0,temp=num;
        while(num > 0) 
        {
            sum += num % 10;
            num /= 10;
        }
        return sum % 2 == 0 ? temp / 2 : (temp - 1) / 2 ;
    }
};