class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        // DFS + memorization (DP)
        // time complexity: O(mn), n is the number of piles. m is the max possible M (approxiamately 1/4 of n)
        // space complexity: O(mn) + stack memory
        // 4ms, beats 90.81%
        
        // Main idea:
        // Compute how many piles can get more than others starting form current step.
        // And res is (total number + number that can 多拿)/2
        int n = piles.size();
        vector<int> sum(n + 1);
        for(int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + piles[i];
        }
        return (sum[sum.size() - 1] + dfs(sum, 1, 1)) / 2;
    }
    
    /* Each dfs calculate 从此步开始 current player's 最多能比对手多拿多少piles */
    int dfs(vector<int>& sum, int start, int M) {
        if(start + 2 * M >= sum.size()) { return sum[sum.size() - 1] - sum[start - 1]; }
        if(memo[start][M]) return memo[start][M];
        int cur_max = INT_MIN;
        for(int i = start; i < start + 2 * M; i++) {
            cur_max = max(cur_max, sum[i] - sum[start - 1] - dfs(sum, i + 1, max(M, i - start + 1)));
        }
        memo[start][M] = cur_max;
        return cur_max;
    }
private:
    int memo[101][32] = {};
};