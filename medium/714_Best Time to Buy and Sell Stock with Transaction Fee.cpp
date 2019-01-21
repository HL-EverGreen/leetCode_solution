class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // array & greedy & DP
        // time complexity: O(n), space complexity: O(1)
        // 104ms, beats 95.1%
        
        // two states:
        // "hold" state: represent the max profit when we hold a stock at time i - 1.
        // "empty" state: represent the max profit when we do not hold a stock at time i - 1.
        int hold = -prices[0], empty = 0;
        for (auto price : prices) {
            // on current time i
            // the max profit of hold state is either we still hold the stock we hold at the i-1 time(hold)
            // or we buy new stock(empty - prices[i])
            int prev_hold = hold;
            hold = max(hold, empty - price);
            // the max profit of enpty state is eighter we still keep our hand empty(empty)
            // or we sell the stock we already hold(hold + prices[i] - fee)
            empty = max(empty, prev_hold + price - fee);
        }
        // return must be empty, because selling is better than holding one stock that has not been sold
        return empty;
    }
};