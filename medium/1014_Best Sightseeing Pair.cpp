class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 68ms, beats 83.64%
        
        // Main idea:
        // Like best time to buy and sell stocks, use cur_max to track current max
        // value (should consider the effect of distance, so -- in each round).
        // Update cur_max in each round.
        
        int res = 0, size = A.size();
        for(int i = 1, cur_max = A[0] - 1; i < size; i++, cur_max--) {
            res = max(res, cur_max + A[i]);
            cur_max = max(cur_max, A[i]);           // Update cur_max
        }
        return res;
    }
};