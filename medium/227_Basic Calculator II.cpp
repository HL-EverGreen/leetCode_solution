class Solution {
public:
    int calculate(string s) {
        // string & calculator
        // method 1:
        // Add '+' at first pos and last pos
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 83.62%
        
        // main idea:
        // Use term to store current result of calculation, add term to res until '+' or '-'
        /*
        s = '+' + s + '+';
        istringstream sin(s);
        char op;
        int term = 0, res = 0, next = 0;
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
        */
        
        // method 2:
        // Using stack
        // time complexity: O(n), space complexity: O(n)
        // 16ms, beats 83.62%
        
        stack<int> num;
        char prev_op = '+';
        int res = 0, cur_num = 0, size = s.size();
        for(int i = 0; i < size; i++) {
            char cur = s[i];
            if(cur == ' ' && i < size - 1) continue;
            if(isdigit(cur)) cur_num = cur_num * 10 + (cur - '0');
            if(!isdigit(cur) || i == size - 1) {
                if(prev_op == '+') num.push(cur_num);
                else if(prev_op == '-') num.push(-cur_num);
                else {
                    int tmp;
                    if(prev_op == '*') tmp = num.top() * cur_num;
                    else if(prev_op == '/') tmp = num.top() / cur_num;
                    num.pop();
                    num.push(tmp);
                }
                cur_num = 0;
                prev_op = cur;
            }
        }
        while(!num.empty()) {
            // cout << num.top() << endl;
            res += num.top();
            num.pop();
        }
        return res;
    }
};