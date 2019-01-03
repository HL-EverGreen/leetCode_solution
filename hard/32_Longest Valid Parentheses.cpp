class Solution {
public:
    int longestValidParentheses(string s) {
        // dynamic programming
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 99%
        
        // method 1
        // using stack
        int res = 0;
        stack<int> pos;
        pos.push(-1);
        
        for(int i = 0; i < s.length(); i++) {
            int top_idx = pos.top();
            if(top_idx != -1 && s[top_idx] == '(' && s[i] == ')') {
                pos.pop();
                res = max(res, i - pos.top());
            } else {
                pos.push(i);
            }
        }
        return res;
        
        
        // method 2
        // DP
        // for any longest[i], it stores the longest length of valid parentheses which is end at i.
        // If s[i] is '(', set longest[i] to 0,because any string end with '(' cannot be a valid one.
        // Else if s[i] is ')', If s[i-1] is '(', longest[i] = longest[i-2] + 2
        // Else if s[i-1] is ')' and s[i-longest[i-1]-1] == '(', longest[i] = longest[i-1] + 2 + longest[i-longest[i-1]-2]
        /*
        if(s.length() <= 1) { return 0; }
        int res = 0;
        vector<int> longest(s.size(), 0);
        for(int i = 1; i < s.length(); i++){
            if(s[i] == ')' && i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '('){
                    longest[i] = longest[i - 1] + 2 + ((i - longest[i - 1] - 2 >= 0)?longest[i - longest[i - 1] - 2] : 0);
                    res = max(longest[i], res);
            }
        }
        return res;
        */
    }
};