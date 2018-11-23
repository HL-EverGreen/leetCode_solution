class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //hash table
        //time complexity: O(n)
        
        unordered_map<char, int> dict;
        int max_len = 0, start = -1;
        
        for(int i = 0; i < s.length(); i++){
            if(dict.find(s[i]) != dict.end()){
                //start can only increase
                start = max(start, dict[s[i]]);
            }
            dict[s[i]] = i;
            max_len = max(max_len, i - start);
        }
        return max_len;
    }
};