class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp
        // time complexity: O(n), space complexity: O(n) -> O(1)
        // 0ms, beats 100%
        
        // main idea:
        // Because of 1 day cool down, buy time should compare with sell[i - 2] - price
        // In O(n) solution, buy[i] means the max profit at day (i - 2) with transaction ending in buying.
        // sell[i] means the max profix at day (i - 2) with transaction ending in selling.

        // O(n) solution
        /*
        int n = prices.size();
        vector<int> buy(n + 2, INT_MIN);
        vector<int> sell(n + 2, 0);
        for(int i = 2; i <= n + 1; i++) {
            int price = prices[i - 2];
            buy[i] = max(buy[i - 1], sell[i - 2] - price);
            sell[i] = max(sell[i - 1], buy[i - 1] + price);
        }
        return sell[n + 1];
        */
        
        // O(1) solution
        int n = prices.size();
        int prev_sell = 0, prev_buy = INT_MIN, cur_sell = 0, cur_buy = INT_MIN;
        for(int i = 0; i < n; i++) {
            int price = prices[i];
            cur_buy = max(prev_buy, prev_sell - price);
            prev_sell = cur_sell;
            cur_sell = max(prev_sell, prev_buy + price);
            prev_buy = cur_buy;
        }
        return cur_sell;
        
    }
};