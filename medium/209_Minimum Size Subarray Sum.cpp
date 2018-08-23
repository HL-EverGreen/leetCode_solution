class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {//sliding window
        //slide window
        //O(n) time complexity
        int n_size=nums.size(),sum=0,start=0,res=INT_MAX;
        for(int i=0;i<n_size;i++){
            sum+=nums[i];
            while(sum>=s){
                res=min(res,i-start+1);
                sum-=nums[start++];
            }
        }
        return res>n_size?0:res;
    }
};