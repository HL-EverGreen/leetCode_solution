class Solution {
public:
    string reverseString(string s) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 97.6%
        
        int i = 0, j = s.length() - 1;
        while(i < j) { swap(s[i++], s[j--]); }
        return s;
        
        // 400ms
        /*
        string res = "";
        for(auto ch : s) {
            res = ch + res;
        }
        return res;
        */
    }
};