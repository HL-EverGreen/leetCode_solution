class Solution {
public:
    int minAddToMakeValid(string S) {
        // parentheses & stack
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // using stack
        stack<char> paren;
        for(auto ch : S) {
            if(paren.empty()) paren.push(ch);
            else if(ch == ')' && paren.top() == '(') paren.pop();
            else paren.push(ch);
        }
        return paren.size();
        
        
        // another O(1) space solution
        /*
        int open = 0, closed = 0;
        for (auto c : S) {
            open = c == '(' ? max(0, open) + 1 : open - 1;
            if (open < 0) ++closed;
        }
        return max(0, open) + closed;
        */
    }
};