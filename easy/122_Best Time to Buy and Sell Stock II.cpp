class Solution {
public:
    int maxProfit(vector<int>& prices) { //sell immediately if price get higher
        int res=0;
        if(prices.size()<=1) return res;
        for(int i=0;i<prices.size()-1;i++){
            if(prices[i+1]>prices[i])
                res+=prices[i+1]-prices[i];
        }
        return res;
    }
};