class Solution {
public:
    int rob(vector<int>& nums) {//dp
        //the main idea is using two dp, one excludes the first element, and the another excludes the last element
        //then return the max value of two dp
        int size=nums.size();
        if(size==0) return 0;
        else if(size==1) return nums[0];
        else if(size==2) return max(nums[0],nums[1]);
        
        vector<int> res1(size-1,0),res2(size-1,0);
        res1[0]=nums[0];res1[1]=max(nums[0],nums[1]);
        res2[0]=nums[1],res2[1]=max(nums[1],nums[2]);
        
        for(int i=2;i<size-1;i++){
            res1[i]=max(res1[i-1],res1[i-2]+nums[i]);
            res2[i]=max(res2[i-1],res2[i-2]+nums[i+1]);
        }
        return max(res1[size-2],res2[size-2]);
    }
};