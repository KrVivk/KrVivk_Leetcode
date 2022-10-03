class Solution {
public:
    bool isLeapYear(int year)
     {
        if (year % 400 == 0) 
            return true;
        if (year % 100 == 0) 
            return false;
        if (year % 4 == 0) 
            return true;
        return false;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int daysOfMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int num = 5;
        for(int i = 1971; i < year; i++){
            if(isLeapYear(i)) num += 366;
            else num += 365;
        }
        if(isLeapYear(year)) 
            daysOfMonth[1]++;
        for(int i = 0; i < month-1; i++){
            num += daysOfMonth[i];
        }
        num += day-1;
        num %= 7;
        return days[num];
    }
};