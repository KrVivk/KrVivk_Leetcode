class Solution {
public:
    int numberOfDays(int year, int month) 
    {
        if(month==4||month==6||month==9||month==11)
            return 30;
        else if(month==2)
        {
        if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            return 29;
            else 
                return 28;
        }
            
            return 31;
    }
};
