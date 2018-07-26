class Solution {
public:
    vector<vector<int>> combine(int n, int k) {//dfs
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res,temp,1,n,k);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& temp, int start, int num, int target){
        if(temp.size()==target){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<=num;i++){
            temp.push_back(i);
            dfs(res,temp,i+1,num,target);
            temp.pop_back();
        }
    }
};