class Solution {
public:
    int numTrees(int n) {//Dynamic programming
        vector<int> res;
        res.push_back(1);
        res.push_back(1);
        for(int i=2;i<=n;i++){
            int temp=0;
            for(int j=0;j<i;j++){
                temp+=res[j]*res[i-j-1];
            }
            res.push_back(temp);
        }
        return res[n];
    }
};