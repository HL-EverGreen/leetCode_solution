class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        if(prices.size()<2) return profit;
        int low=prices[0];
        int high;
        
        for(int i=1;i<prices.size();i++){
            if(prices[i]<low){
                low=prices[i];
            }
            else{
                high=prices[i];
                profit=max(profit,high-low);
            }
        }
        return profit;
        
    }
};