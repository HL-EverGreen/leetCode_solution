class Solution {
public:
    string removeOuterParentheses(string S) {
        // Parenthesis
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 97.89%
        
        // Main idea:
        // Use open to count number of unpaired parenthesis, and add character according to the open count
        int open = 0;
        string res;
        
        for(char ch : S) {
            if(ch == '(' && open++ > 0) { res += ch; }
            else if(ch == ')' && open-- > 1) { res += ch; }
        }
        return res;
    }
};