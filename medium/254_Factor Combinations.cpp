class Solution {
public:
    vector<vector<int>> getFactors(int n) {//dfs
        vector<vector<int>> res;
        vector<int> temp;
        dfs(res,temp,2,n);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& temp, int start, int n){
        for(int i=start;i<=sqrt(n);i++){
            if(n%i==0){
                temp.push_back(i);
                temp.push_back(n/i);
                res.push_back(temp);
                temp.pop_back();
                dfs(res,temp,i,n/i);
                temp.pop_back();
            }
        }
    }
};