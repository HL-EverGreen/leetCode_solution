class Solution {
public:
    string reverseWords(string s) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 20ms, beats 95.02%
        
        // Main idea:
        // Use front to track last blank's position.
        // And update front continually
        int front = 0, len = s.length();
        for(int i = 0; i <= len; i++) {
            if(s[i] == ' ' || i == len) {
                reverse(&s[front], &s[i]);
                front = i + 1;
            }
        }
        return s;
    }
};