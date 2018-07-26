class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        dfs(res,temp,candidates,0,0,target);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& temp, vector<int>& can, int start, int sum, int target){
        if(sum==target){
            res.push_back(temp);
        }
        for(int i=start;i<can.size();i++){
            if(sum+can[i]>target) return;
            temp.push_back(can[i]);
            dfs(res,temp,can,i,sum+can[i],target);
            temp.pop_back();
        }
    }
};