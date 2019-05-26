class Solution {
public:
    const vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    int uniqueMorseRepresentations(vector<string>& words) {
        // set
        // time complexity: O(nk), space complexity: O(n)
        // 4ms, beats 97.59%
        
        // Main idea:
        // Use unordered_set to record each translation result
        unordered_set<string> res;
        
        for(auto word : words) {
            string morse;
            for(auto ch : word) {
                morse += dict[ch - 'a'];
            }
            res.insert(morse);
        }
        return res.size();
    }
};