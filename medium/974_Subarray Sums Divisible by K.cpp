class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        // prefix sum
        // time complexity: O(n), space complexity: O(n)
        // 56ms, beats 86.87%
        
        // Similar with LC560
        // But compute prefix with mod by K.
        // e.g. (a[0] + ... + a[10]) mod k = m, and (a[0] + ... + a[12]) mod k = m
        // So a[11] + a[12] = nk, we find a subarray satistying the requirement
        
        vector<int> modCnt(K, 0);
        modCnt[0] = 1;
        int mod = 0, res = 0;
        for(auto num : A) {
            mod = (mod + num % K + K) % K;
            res += modCnt[mod];
            modCnt[mod]++;
        }
        return res;
    }
};