class Solution {
public:
    string reverseVowels(string s) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 12ms, beats 81.34%
        
        int i = 0, j = s.length() - 1;
        while(i < j) {
            while(i < j && !isVowel(tolower(s[i]))) i++;
            while(i < j && !isVowel(tolower(s[j]))) j--;
            swap(s[i++], s[j--]);
        }
        return s;
    }
    
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};