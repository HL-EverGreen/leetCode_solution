class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {//dp
        //dp[j] represent the minimum cost when paint Jth color
        int size_n=costs.size();
        if(size_n==0) return 0;
        int size_k=costs[0].size();
        if(size_k==0) return 0;
        vector<int> dp(size_k,0);
        int min1_old,min2_old,min1,min2;
        for(int i=0;i<size_n;i++){
            min1_old=(i==0?0:min1); //min1_old: the smallest cost in (i-1) round
            min2_old=(i==0?0:min2); //min2_old: the second smallest cost in (i-1) round
            min1=INT_MAX;          
            min2=INT_MAX;         
            for(int j=0;j<size_k;j++){
                if(dp[j]!=min1_old || min1_old==min2_old) //if the cheapest plan in last round does not ends with Jth color, choose it
                    dp[j]=min1_old+costs[i][j];
                else if(dp[j]==min1_old)                  //if the cheapest plan in last round ends paint with Jth color, choose the second
                                                          // cheapest plan in the last round (to avoid adjancent house having same color)
                    dp[j]=min2_old+costs[i][j];
                if(min1<=dp[j]){
                    min2=min(min2,dp[j]);
                }else{
                    min2=min1;
                    min1=dp[j];
                }
            }
        }
        return min1;
        
    }
};