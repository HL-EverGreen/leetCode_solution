class Solution {
public:
    int maxSubArray(vector<int>& nums) {//dp
        int sum=0,res=nums[0];
        for(auto num:nums){
            sum+=num;
            res=max(res,sum);
            sum=max(sum,0);
        }
        return res;
    }
};