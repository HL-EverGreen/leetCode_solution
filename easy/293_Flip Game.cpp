class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        string temp;
        if(s.length()<2)
            return res;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='+' && s[i+1]=='+'){
                temp=s;
                temp[i]='-';
                temp[i+1]='-';
                res.push_back(temp);
            }        
        }
        return res;
    }
};