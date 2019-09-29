class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // dp
        // time complexity: O(n^2), space complexity: O(n^2)
        // 0ms, beats 100%
        
        // Main idea:
        // Since the condition is the same for each selection by either player, so we can use recursion.
        // Furthur, since there is only two branch, we can find the optimal substructure among the problem, we could use DP.
        // Let scoreGap[i][j] represents that the 最大净得分 that current player can gain against the another player for array num[i~j]
        // So the result is whether scoreGap[0][N - 1] >= 0, since the player 1 picks first.
        
        // And:                   choose the front number,        choose the back number
        // scoreGap[i][j] = max(nums[i] - scoreGap[i + 1][j], nums[j] - scoreGap[i][j - 1]);
        
        int N = nums.size();
        vector<vector<int>> scoreGap(N, vector<int>(N, INT_MIN));
        for(int i = 0; i < N; ++i) scoreGap[i][i] = nums[i];    // For array num[i~i], the max profit can only be num[i]
        for(int len = 1; len < N; ++len) {
            for(int start = 0; start + len < N; ++start) {
                int end = start + len;
                scoreGap[start][end] = max(nums[start] - scoreGap[start + 1][end], nums[end] - scoreGap[start][end - 1]);
            }
        }
        return scoreGap[0][N - 1] >= 0;
    }
};