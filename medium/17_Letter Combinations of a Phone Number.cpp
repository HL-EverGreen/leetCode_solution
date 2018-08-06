class Solution {
public:
    string dict[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string tmp="";
        if(!digits.length()) return res;
        getAllCombinations(digits,res,tmp,0);
        return res;
    }
    
    void getAllCombinations(string digits, vector<string>& res, string tmp, int index){ //dfs
        if(index==digits.length()){
            res.push_back(tmp);
            return;
        }
        int num=digits[index]-'2';
        for(int i=0;i<dict[num].length();i++){
            getAllCombinations(digits,res,tmp+dict[num][i],index+1);
        }
    }
};