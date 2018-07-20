class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;    
    vector<vector<int>> subsets(vector<int>& nums) {
        int index=0;
        dfs(nums,temp,index);
        return res;
        }
    
    void dfs(vector<int>& nums, vector<int>& temp, int index){//dfs
        res.push_back(temp);
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            dfs(nums,temp,i+1);
            temp.pop_back();
        }
    }
};