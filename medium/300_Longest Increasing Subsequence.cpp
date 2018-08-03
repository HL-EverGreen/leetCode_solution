class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //Time complexity: O(nlogn)
        //Using an timely updating sequence, when a smaller number come up, replace the corresponding old bigger number with it
        vector<int> res;
        for(auto num:nums){
            auto it=lower_bound(res.begin(),res.end(),num);//use binary search to find the index of first number bigger than num
            if(it==res.end()) res.push_back(num);
            else *it=num;
        }
        return res.size();
        
        
        
        //Time complexity: O(n^2)
        //Using DP, the essensial of dp is to find the meaning of dp[i]
        //Here, the dp[i] represents the length of the longest increasing sequence which ends with nums[i]
        //So that when nums[j]>nums[i],dp[j]=max(dp[j],dp[i]+1)
        /*
        if(nums.size()==0) return 0;
        int size=nums.size(),res=1;
        vector<int> dp(size,1);
        for(int i=1;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            res=max(res,dp[i]);
        }
        return res;
        */
    }
};