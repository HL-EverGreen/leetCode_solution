class Solution {
public:
    bool validPalindrome(string s) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 100ms, beats 89.66%
        
        // Main idea:
        // Act like normal palindrome determine algorighm.
        // When detect mismatch, continue compare s[l+1~r] and s[l~r-1]
        int N = s.length();
        int l = 0, r = N - 1;
        while(l < r) {
            if(s[l] != s[r]) return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
            ++l;
            --r;
        }
        return true;
    }
    
    // Compare whether s[l ~ r] is palindrome
    bool isPalindrome(string s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};