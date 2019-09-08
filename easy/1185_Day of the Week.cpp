class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        // math
        // time complexity: O(1), space complexity: O(1)
        // 0ms, beats 100%
        
        // 1971-1-1 is friday
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string dates[7] = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        int count = 0;
        
        for(int i = 1971; i < year; ++i) count += (isBigYear(i) ? 366 : 365);
        for(int i = 1; i < month; ++i) count += days[i - 1];
        if(isBigYear(year) && month > 2) count += 1;
        count += day - 1;
        
        count = count % 7;
        return dates[count];
    }
    
    bool isBigYear(int year) {
        return year % 4 == 0;
    }
};

// Zella formula
vector<string> days= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
string dayOfTheWeek(int d, int m, int y, int c = 0) {
    if (m < 3) m += 12, y -= 1;
    c = y / 100, y = y % 100;
    int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
    return days[(w + 7) % 7];
}