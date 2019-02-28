class Solution {
public:
    int calculate(string s) {
        // string & calculator
        // time complexity: O(n), space complexity: O(n)
        // 12ms, beats 70.1%
        
        int i = 0;
        return calExpr(s, i);
    }
    
    long calExpr(string& s, int& i) {
        vector<long> num;
        int size = s.length();
        char last_op = '+';
        for(; i < size && last_op != ')'; i++) {
            if(s[i] == ' ') continue;
            long cur = (s[i] == '(' ? calExpr(s, ++i) : calNum(s, i));
            switch(last_op) {
                case '+': num.push_back(cur); break;
                case '-': num.push_back(-cur); break;
                case '*': num.back() *= cur; break;
                case '/': num.back() /= cur; break;
            }
            if(i < size) last_op = s[i];
        }
        long res = 0;
        for(auto n : num) res += n;
        return res;
    }
    
    long calNum(string&s, int& i) {
        long res = 0, size = s.length();
        while(i < size && isdigit(s[i])) {
            res = 10 * res + s[i] - '0';
            i++;
        }
        return res;
    }
};