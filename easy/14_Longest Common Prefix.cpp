class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // string
        // time complexity: O(nk), k is the length of first string, space complexity: O(1)
        // 4ms, beats 99.95%
        
        string prefix;
        for(int index = 0; strs.size() > 0; prefix += strs[0][index++]) {       // index: ith character in first string
            for(int i = 0; i < strs.size(); i++) {                              // i: string in vector
                if(index >= strs[i].length() || (i > 0 && strs[i][index] != strs[i - 1][index])) { return prefix; }
            }
        }
        return prefix;
    }
};