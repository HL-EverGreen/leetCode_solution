class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {//dp
        //dp[i] presents whether there is any existing word in dictionary ends with s[i-1]
        if(wordDict.size()==0) return false;
        int s_size=s.size();
        vector<bool> dp(s_size+1,false);
        dp[0]=true;
        for(int i=1;i<=s_size;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    if(find(wordDict.begin(),wordDict.end(),s.substr(j,i-j))!=wordDict.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s_size];
    }
};