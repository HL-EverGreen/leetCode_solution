class Solution {
public:
    bool isPalindrome(string s) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 98.46%
        
        for(int i = 0, j = s.length() - 1; i < j; i++, j--) {
            while(i < j && !isalnum(s[i])) i++;
            while(i < j && !isalnum(s[j])) j--;
            if(toupper(s[i]) != toupper(s[j])) return false;
        }
        return true;
    }
};