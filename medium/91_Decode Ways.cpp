class Solution {
public:
    int numDecodings(string s) {
        // dynamic programming
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // dec_num[i] means total decode way for substring s[0]...s[i - 1], dec_num[0] means empty string
        // main idea: if s[i] and (s[i - 1], s[i]) is valid, the total decode number of string ending at s[i] is dec_num[i - 1] + dec_num[i - 2]
        int n = s.size();
        if(n == 0 || s[0] == '0') { return 0; }
        else if(n == 1) { return 1; }
        vector<int> dec_num(s.length() + 1, 1);
        for(int i = 2; i <= n; i++) {
            if(isValid(s[i - 1]) && isValid(s[i - 2], s[i - 1])) { 
                dec_num[i] = dec_num[i - 2] + dec_num[i - 1]; 
            } else if(isValid(s[i - 1]) && !isValid(s[i - 2], s[i - 1])) {
                dec_num[i] = dec_num[i - 1];
            } else if(!isValid(s[i - 1]) && isValid(s[i - 2], s[i - 1])) {
                dec_num[i] = dec_num[i - 2];
            } else {
                return 0;
            }
        }
        return dec_num[n];
        
        // or it can be written in O(1) space, which only keep last two dec_num
        /*
        if(n == 0 || s[0] == '0') return 0;
        if(n == 1) return 1;
        int res = 0,fn_1 = 1,fn_2 = 1;
        for(int i = 1;i < n;i++){
            int temp = fn_1;
            if(isValid(s[i])&&isValid(s[i-1],s[i]))  res+=fn_1+fn_2;
            if(!isValid(s[i])&&isValid(s[i-1],s[i])) res+=fn_2;
            if(isValid(s[i])&&!isValid(s[i-1],s[i])) res+=fn_1;
            if(!isValid(s[i])&&!isValid(s[i-1],s[i]))  return 0;
            fn_1 = res;
            fn_2 = temp;
            res = 0;
        }
        return fn_1;
        */
    }
    
    bool isValid(char a) {
        return a != '0';
    }
    
    bool isValid(char a, char b) {
        return a == '1' || (a == '2' && b <= '6');
    }
};