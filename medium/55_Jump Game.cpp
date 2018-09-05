class Solution {
public:
    bool canJump(vector<int>& nums) {//update_continually_rather_than_DP
        //update maximum reach range continually, if reach area >= nums.size()-1, return true
        //time complexity: O(n)
        int reach=0, i=0, n_size=nums.size();
        for(;i<n_size-1 && i<=reach;i++){
            reach=max(reach, i+nums[i]);
        }
        return reach>=n_size-1;
        
        //dp
        //time complexity: O(n^2), very time-consuming
        /*
        int n_size=nums.size();
        vector<bool> dp(n_size,false);
        dp[0]=true;
        for(int i=0;i<n_size;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && nums[j]+j>=i){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n_size-1];
        */
    }
};