class Solution {
public:
    int strStr(string haystack, string needle) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.82%
        
        // substr(i, 0) = ""
        int h_size = haystack.size(), n_size = needle.size();
        for(int i = 0; i <= h_size - n_size; i++) {
            if(haystack.substr(i, n_size) == needle) return i;
        }
        return -1;
    }
};