class Solution {
public:
    vector<vector<string>> partition(string s) {//dfs
        vector<vector<string>> res;
        vector<string> tmp;
        if(s.empty()) return res;
        dfs(res,tmp,s,0);
        return res;
    }
    
    void dfs(vector<vector<string>>& res, vector<string>& tmp, string& s, int index){ //dfs every palindrome substr
        if(index==s.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(ifPalindrome(s,index,i)) {
                tmp.push_back(s.substr(index,i-index+1));
                dfs(res,tmp,s,i+1);
                tmp.pop_back();    
            }
        }
    }
    
    bool ifPalindrome(string& s, int start, int end){ //transfer &s instead directly s to save running time
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};