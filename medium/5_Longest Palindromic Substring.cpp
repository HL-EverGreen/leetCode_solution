class Solution {
public:
    string longestPalindrome(string s) { //palindrome string
        //time complexity: O(n)
        //beats 99.75%
        
        if(s.length() <= 1) return s;
        int min_start = 0, max_len = 1;
        for(int count = 0; count < s.length();){
            //if the rest length is less than half of the current max length, then break
            if(s.length() - count <= max_len / 2) {
                break;
            }
            
            int start = count, end = count;
            
            //skip duplicates
            while(end < s.length() - 1 && s[end + 1] == s[end]){
                end++;
            }
            count = end + 1;
            
            //expand the substring
            while(start > 0 && end < s.length() - 1 && s[start - 1] == s[end + 1]){
                start--;
                end++;
            }
            
            //update longest sub palindrome string
            int new_len = end - start + 1;
            if(new_len > max_len){
                min_start = start;
                max_len = new_len;
            }
        }
        return s.substr(min_start, max_len);
    }
};