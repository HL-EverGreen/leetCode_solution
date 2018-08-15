class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {//dfs
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        dfs(res,tmp,candidates,target,0,0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& tmp, vector<int>& candidates, int target, int sum, int start){
        if(sum==target){
            res.push_back(tmp);
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            while(i>0 && candidates[i]==candidates[i-1] && i>start) i++; //to ensure no duplicates in res
            int cand=candidates[i];
            if(sum+cand>target) return;
            tmp.push_back(cand);
            dfs(res,tmp,candidates,target,sum+cand,i+1);
            tmp.pop_back();
        }
    }
};