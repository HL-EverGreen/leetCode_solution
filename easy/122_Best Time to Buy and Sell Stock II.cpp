class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.40%
        
        int res = 0;
        for(int i = 1; i < prices.size(); i++) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};