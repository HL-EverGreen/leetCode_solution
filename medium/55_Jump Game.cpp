class Solution {
public:
    bool canJump(vector<int>& nums) {
        // array
        // time complexity: O(n)
        // update max_reach range continually, and compare max_reach with the destination
        int max_reach = 0, n_size = nums.size();
        for(int i = 0; i < n_size - 1 && i <= max_reach; i++) {
            max_reach = max(max_reach, nums[i] + i);
        }
        return max_reach >= n_size - 1;
        
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