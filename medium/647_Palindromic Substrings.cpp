class Solution {
public:
    int countSubstrings(string s) {
        // string & palindrome
        // time complexity: O(n^2), space complexity: O(1)
        // 8ms, beats 100%
        
        // main idea:
        // for each char in s, try expand this char to odd string or even string in symmetry, check if palindrome
        
        int res = 0, sSize = s.length();
        for(int i = 0; i < sSize; i++) {
            for(int j = 0; i - j >= 0 && i + j < sSize; j++) {              // for odd length substring
                if(s[i - j] == s[i + j]) res++;
                else break;
            }
            for(int j = 0; i - 1 - j >= 0 && i + j < sSize; j++) {          // for even length substring
                if(s[i - 1 - j] == s[i + j]) res++;
                else break;
            }
        }
        return res;
    }
};