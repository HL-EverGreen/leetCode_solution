class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // array & DP
        // time complexity: O(n), space complexity: 0(1)
        // 4ms, beats 99.70%
        
        // use four states to store current optimal solution and update it iteratively
        int state[2][4] = {INT_MIN, 0, INT_MIN, 0};
        int day = prices.size(), cur = 0, next = 1;
        
        for(int i = 0; i < day; i++) {
            state[next][0] = max(state[cur][0], -prices[i]);                // 1 buy
            state[next][1] = max(state[cur][1], state[cur][0] + prices[i]); // 1 buy & 1 sell
            state[next][2] = max(state[cur][2], state[cur][1] - prices[i]); // 2 buy & 1 sell
            state[next][3] = max(state[cur][3], state[cur][2] + prices[i]); // 2 buy & 2 sell
            swap(next, cur);
        }
        return max(state[cur][1], state[cur][3]);
    }
};