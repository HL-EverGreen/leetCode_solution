class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.51%
        
        int day = prices.size(), max_profit = 0, low_price = INT_MAX;
        if(day < 2) { return max_profit; }
        
        for(int i = 0; i < day; i++) {
            low_price = min(low_price, prices[i]);
            max_profit = max(max_profit, prices[i] - low_price);
        }
        return max_profit;
    }
};