class Solution {
public:
    bool detectCapitalUse(string word) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Use `flg` to id whether last one is uppercase.
        // `flg` can only transform from true to false
        bool flg = isupper(word[0]);
        for(int i = 1; i < word.length(); i++) {
            if(islower(word[i])) { 
                if(flg && i > 1) { return false; }          // 'FFFFFf'
                flg = false; 
            } else if(!flg) { return false; }               // 'fFFF'
        }
        return true;
    }
};