class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // parenthesis & dfs
        // 84ms, beats 43.75%
        // Main idea:
        // 1. track number of parenthesis needed to be deleted
        // 2. for "(", delete this or keep this and add pair by 1
        // 3. for ")", delete this or keep this and decrease pair by 1
        
        unordered_set<string> result;
        int remove_left = 0, remove_right = 0;
        for(auto ch : s) {
            if(ch == '(') remove_left++;
            else if(ch == ')') {
                if(remove_left > 0) remove_left--;
                else remove_right++;
            }
        }
        findValidParen(result, s, "", remove_left, remove_right, 0, 0);
        vector<string> res(result.begin(), result.end());
        return res;
    }
    
    // dfs
    void findValidParen(unordered_set<string>& result, string s, string path, int remove_left, int remove_right, int rem_pair, int index) {
        if(index == s.length()) {
            if(remove_left == 0 && remove_right == 0 && rem_pair == 0) result.insert(path);
            return;
        }
        
        if(s[index] == '(') {
            if(remove_left > 0) findValidParen(result, s, path, remove_left - 1, remove_right, rem_pair, index + 1);        // delete it
            findValidParen(result, s, path + "(", remove_left, remove_right, rem_pair + 1, index + 1);                      // skip it and add pair by one
        } else if(s[index] == ')') {
            if(remove_right > 0) findValidParen(result, s, path, remove_left, remove_right - 1, rem_pair, index + 1);       // delete it
            if(rem_pair > 0) findValidParen(result, s, path + ")", remove_left, remove_right, rem_pair - 1, index + 1);     // keep it and reduce pair by one
        } else findValidParen(result, s, path + s[index], remove_left, remove_right, rem_pair, index + 1);                  // keep the non "(" or ")" char
    }
};