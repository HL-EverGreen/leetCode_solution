class Solution {
public:
    string toLowerCase(string str) {
        // String
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 93.56%
        
        // Main idea:
        // Simply traverse the string and make adjustment
        int gap = 'a' - 'A';
        for(char& ch : str) {
            if(ch >= 'A' && ch <= 'Z') {
                ch += gap;
            }
        }
        return str;
    }
};