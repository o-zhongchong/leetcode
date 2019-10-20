class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> ret = {"Monday", "Tuesday", "Wednesday", "Thursday",                             "Friday", "Saturday", "Sunday"};
        vector<int> days = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30,             31};
        int sum=0;
        
        for(int i=1971; i<year; ++i)
            sum += 365 + isLeapYear(i);
        for(int i=1; i < month; ++i)
            sum += days[i-1];
        sum += day;
        
        return ret[ (sum+3) % 7];
    }
protected:
    inline bool isLeapYear(int y)
    {
        if( (y%4 == 0 && y%100 !=0) || y%400 == 0)
            return true;
        return false;
    }
};