class Solution {
public:
    string addStrings(string num1, string num2) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 96.10%
        
        // Main idea:
        // Like linked list add, just add from back to front and use carry to present 进位
        int n1 = num1.size(), n2 = num2.size(), carry = 0, i = n1 - 1, j = n2 - 1;
        string res;
        
        while(i >= 0 || j >= 0 || carry) {
            int c1 = i >= 0 ? num1[i--] - '0' : 0;
            int c2 = j >= 0 ? num2[j--] - '0' : 0;
            carry = c1 + c2 + carry;
            int cur = carry % 10;
            carry /= 10;
            res += ('0' + cur);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};