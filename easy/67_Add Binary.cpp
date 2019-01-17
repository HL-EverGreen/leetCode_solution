class Solution {
public:
    string addBinary(string a, string b) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.53%
        
        // add from back to front, add up by a[i], b[j] and carry
        int n1 = a.length() - 1, n2 = b.length() - 1, carry = 0;
        string res ="";
        while(n1 >= 0 || n2 >= 0 || carry) {
            int cur = (n1 >=0 ? a[n1--] - '0' : 0) + (n2 >=0 ? b[n2--] - '0' : 0) + carry;
            carry = cur / 2;
            cur %= 2;
            res = to_string(cur) + res;
        }
        return res;
    }
};