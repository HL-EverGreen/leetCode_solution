class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            res.push_back(vector<int>());
            res[i].push_back(1);
            for(int j=1;j<i;j++)
                res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            if(i!=0)
                res[i].push_back(1);
        }
        return res;
    }
};