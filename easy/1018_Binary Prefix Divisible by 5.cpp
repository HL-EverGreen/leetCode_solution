class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        // math & array
        // time complexity: O(n), space complexity: O(1)
        // 12ms, beats 85.78%
        
        // Main idea:
        // Only keep the num % 5, because once K % 5 == 0, K的任意整数倍也都会被5整除，所以可以减去K，只留未被整除的余数.
        // So in each turn, num = (2 * num + new_int) % 5
        
        vector<bool> res;
        int num = 0;
        for(auto& a : A) {
            num = (2 * num + a) % 5;
            res.push_back(!num);
        }
        return res;
    }
};