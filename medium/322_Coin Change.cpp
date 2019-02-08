class Solution {
public:
    int numSquares(int n) {//dp
        // array & DP
        // time complexity: O(nk), n is the amount, k is the number of coins
        // 16ms, beats 99%
        
        // minCoinNum[i] represents minimum number of coins needed to change for amount i
        int cSize = coins.size();
        vector<int> minCoinNum(amount + 1, amount + 1);
        minCoinNum[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < cSize; j++) {
                if(i >= coins[j]) minCoinNum[i] = min(minCoinNum[i], minCoinNum[i - coins[j]] + 1);
            }
        }
        return minCoinNum[amount] > amount ? -1 : minCoinNum[amount];
    }
};