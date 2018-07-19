class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> ans;
        findCombinationSum(res,ans,1,k,n,0);
        return res;
    }
    
    void findCombinationSum(vector<vector<int>> &res, vector<int> &ans, int start, int k, int n, int sum){
        if(ans.size()==k&&sum==n){
            res.push_back(ans);
            return;
        }
        else if(ans.size()>k || sum>n) return;
        
        for(int i=start;i<=9;i++){
            ans.push_back(i);
            findCombinationSum(res,ans,i+1,k,n,sum+i);
            ans.pop_back();
        }
    }
};