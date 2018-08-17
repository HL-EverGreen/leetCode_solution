class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {//dfs
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        perm(res,nums,0,nums.size());
        return res;
    }
    
    void perm(vector<vector<int>>& res,vector<int> nums, int start, int end){ //instead using vector<int>& nums to avoid unnecessary changes
        if(start==end-1) res.push_back(nums);
        else{
            for(int index=start;index<end;index++){
                if(index!=start && nums[index]==nums[start]) continue;
                swap(nums[index],nums[start]);
                perm(res,nums,start+1,end);
            }
        }
    }
};