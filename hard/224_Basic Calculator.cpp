class Solution {
public:
    int calculate(string s) {
        // string & calculator
        // time complexity: O(n), space complexity: O(k), k is the depth of parenthesis
        // 12ms, beats 98.66%
        
        // main idea:
        // signs.top() is + or - after flipping according to former + or -
        // And all operations are executed according to signs.top()
        // When enter a new depth parentheis, calculate current signs.top() = signs.top() * cur_op
        // When leave a parenthesis, pop top of the stack
        
        stack<int> signs;
        int cur_op = 1, cur_num = 0, res = 0;
        signs.push(1);
        
        for(auto ch : s) {
            if(ch >= '0' && ch <= '9') cur_num = cur_num * 10 + (ch - '0');
            else if(ch == '+' || ch == '-') {
                res += cur_num * cur_op * signs.top();
                cur_num = 0;
                cur_op = (ch == '+' ? 1 : -1);
            } else if(ch == '(') {
                signs.push(signs.top() * cur_op);
                cur_op = 1;
            } else if(ch == ')') {
                res += cur_num * cur_op * signs.top();
                signs.pop();
                cur_op = 1;
                cur_num = 0;
            }
        }
        
        if(cur_num) res += cur_op * signs.top() * cur_num;
        return res;
    }
};