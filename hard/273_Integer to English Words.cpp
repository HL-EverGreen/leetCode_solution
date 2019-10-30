class Solution {
public:
    string numberToWords(int num) {
        // string
        // time complexity: O(1), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Straight forward, store unit in array
        // *Notice the use format of static string array!
        
        if(num == 0) return "Zero";
        return int2string(num).substr(1);   // Remove heading whitespace
    }
private:
    static const char* const tens[];
    static const char* const digits[];
    static const int billion, million, thousand, hundred;
    string int2string(int num) {
        if(num >= billion) {
            return int2string(num / billion) + " Billion" + int2string(num % billion);
        } else if(num >= million) {
            return int2string(num / million) + " Million" + int2string(num % million);
        } else if(num >= thousand) {
            return int2string(num / thousand) + " Thousand" + int2string(num % thousand);
        } else if(num >= hundred) {
            return int2string(num / hundred) + " Hundred" + int2string(num % hundred);
        } else if(num >= 20) {
            return string(" ") + tens[num / 10] + int2string(num % 10);
        } else if(num >= 1) {
            return string(" ") + digits[num];
        } else return "";
    }
};

const char* const Solution::tens[] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
const char* const Solution::digits[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                                 "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const int Solution::billion = 1000000000;
const int Solution::million = 1000000;
const int Solution::thousand = 1000;
const int Solution::hundred = 100;
