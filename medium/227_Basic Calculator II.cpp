class Solution {
public:
    int calculate(string s) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 12ms, beats 98.97%
        
        istringstream sin('+' + s + '+');
        char op;
        int res = 0, term = 0, next;
        while(sin >> op) {
            if(op == '+' || op == '-') {
                res += term;
                sin >> term;
                term *= (op == '+' ? 1 : -1);
            } else {
                sin >> next;
                if(op == '*') term *= next;
                else term /= next;
            }
        }
        return res;
    }
};