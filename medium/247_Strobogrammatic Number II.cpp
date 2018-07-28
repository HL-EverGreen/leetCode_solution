class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return solve(n,n);
    }
    
    vector<string> solve(int count, int num){//recursive
        if(count==0) return vector<string>({""});
        if(count==1) return vector<string>({"0","1","8"});
        vector<string> temp=solve(count-2,num),res;
        for(int i=0;i<temp.size();i++){
            if(count!=num)
                res.push_back("0"+temp[i]+"0");
            res.push_back("1"+temp[i]+"1");
            res.push_back("6"+temp[i]+"9");
            res.push_back("8"+temp[i]+"8");
            res.push_back("9"+temp[i]+"6");
        }
        return res;
    }
};