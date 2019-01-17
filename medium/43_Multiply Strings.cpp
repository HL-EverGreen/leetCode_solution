class Solution {
public:
    string multiply(string num1, string num2) {
        // string
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 100%
        
        // for each digit in num1, multiply with num2, store in res
        int n1 = num1.length() - 1, n2 = num2.length() - 1;
        string res(n1 + n2 + 2, '0');
        
        for(int i = n1; i>= 0; i--) {
            int carry = 0;
            for(int j = n2; j >= 0; j--) {
                int cur = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                res[i + j + 1] = '0' + cur % 10;
                carry = cur / 10;
            }
            res[i] = '0' + carry;
        }
        
        for(int i = 0; i < res.length(); i++) {
            if(res[i] != '0') return res.substr(i);
        }
        return "0";
    }
};