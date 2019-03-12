class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        // array & palindrome
        // time complexity: O(n*k^2), k is the average length of word
        // space complexity: O(n)
        // 240ms, beats 83.04%
        
        // main idea:
        // Record each word's reversion into hash table
        // Check each word in words, and divide it into left and right parts, compare if left or right is in dict
        
        unordered_map<string, int> dict;
        vector<vector<int>> res;
        int size = words.size();
        
        // Build dictionary
        for(int i = 0; i < size; i++) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        
        // Handle edge case: ("" + palindrome)
        if(dict.count("")) {
            for(int i = 0; i < size; i++) {
                if(words[i] != "" && isPalin(words[i])) res.push_back({dict[""], i});
            }
        }
        
        // Check each word
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j);
                if(dict.count(left) && isPalin(right) && dict[left] != i) res.push_back({i, dict[left]});       // cover (palindrome + "") case
                if(dict.count(right) && isPalin(left) && dict[right] != i) res.push_back({dict[right], i});
            }
        }
        return res;
    }
    
    // Determine whether input string is palindrome
    bool isPalin(string& str) {
        int i = 0, j = str.length() - 1;
        while(i < j) {
            if(str[i++] != str[j--]) return false;
        }
        return true;
    }
};