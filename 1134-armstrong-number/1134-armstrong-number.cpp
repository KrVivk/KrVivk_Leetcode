class Solution {
public:
    bool isArmstrong(int n) 
    {
        int sum=0,d=0,k=0,temp=n,p=n,dig;
        while(p>0)
        {
            d = p % 10;
            k++;
            p = p/10;
        }
        while(temp>0)
        {
            dig = temp%10;
            sum += pow(dig,k);
            temp = temp/10;
        }
        if(sum == n)
            return true;
        else 
            return false;
    }
};
