class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dynamic programming

        // method 1
        // dynamic programming
        // time complexity: O(nk), space complexity: O(k)
        // 4ms, beats 95.97%
        
        // like best time to buy and sell stock III, but each epoch update from back to front, so doesn't need 2D array
        int len = prices.size();
        if (len < 2) return 0;
        if (k > len / 2) { // simple case
            int ans = 0;
            for (int i = 1; i < len; ++i){
                ans += max(prices[i] - prices[i - 1], 0);
            }
            return ans;
        }
        int hold[k + 1];
        int rele[k + 1];
        for (int i = 0; i <= k; ++i){
            hold[i] = INT_MIN;
            rele[i] = 0;
        }
        int cur;
        for (int i = 0; i<len; ++i){
            cur = prices[i];
            for(int j = k; j > 0; --j){
                rele[j] = max(rele[j], hold[j] + cur);          // sell
                hold[j] = max(hold[j], rele[j - 1] - cur);      // buy
            }
        }
        return rele[k];
        
        
        // method 2
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 95.97%
        
        // Step 1: Find out all profit opportunities  
        /*
        vector<int> profits;
        stack<pair<int, int>> vps;      // store valley-peak pairs
        
        int v, p = -1, size = prices.size();
        while(true) {
            // find next valley-peak pair
            for(v = p + 1; (v + 1 < size) && (prices[v] >= prices[v + 1]); v++);
            for(p = v; (p + 1 < size) && (prices[p] <= prices[p + 1]); p++);
            
            // v==p means that both v and p reach the end of the array
            if(v == p) { break; }  
            
            // Consider two transactions (v1, p1) (back of the stack) and (v2, p2) (the new-found).
            // If prices[v1] >= prices[v2], 
            // it is meaningless to combine the two transactions.
            // Save of profit of (v1, p1), and pop it out of the record.
            while((!vps.empty()) && (prices[v] <= prices[vps.top().first])) {
                profits.push_back(prices[vps.top().second] - prices[vps.top().first]);
                vps.pop();
            }
            
            // If prices[v1]<prices[v2] and prices[p1]<prices[p2], 
            // then it is meaningful to combine the two transactions
            // update (v1, p1) to (v1, p2), and save the profit of (v2, p1)
            while((!vps.empty()) && (prices[p] >= prices[vps.top().second])) {
                profits.push_back(prices[vps.top().second] - prices[v]);
                v = vps.top().first;
                vps.pop();
            }
            
            // save the new-found valley-peak pair
            vps.emplace(v, p);
        }
          
        // save all remaining profits
        while(!vps.empty()) {
            profits.push_back(prices[vps.top().second] - prices[vps.top().first]);
            vps.pop();
        }
        
        // Step 2: Calculate the k highest profits
        int res;
        if(profits.size() <= k) {
            res = accumulate(profits.begin(), profits.end(), 0);
        } else {
            nth_element(profits.begin(), profits.end() - k, profits.end());                     // time complexity: O(n)
            res = accumulate(profits.end() - k, profits.end(), 0);                              // 计算最大的k个的元素的和
        }
        return res;
        */
    }
};