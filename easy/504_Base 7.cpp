class Solution {
public:
    string convertToBase7(int num) {
        // math
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // straight forward
        if(num == 0) { return "0"; }
        string res;
        int t = abs(num);
        
        while(t) {
            res = to_string(t % 7) + res;
            t /= 7;
        }
        if(num < 0) { res = '-' + res; }
        return res;
    }
};