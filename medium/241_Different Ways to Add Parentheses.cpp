class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i=0;i<input.size();i++){
            char cur=input[i];
            if(cur=='+'||cur=='-'||cur=='*'){
                vector<int>res1=diffWaysToCompute(input.substr(0,i)); //recursive
                vector<int>res2=diffWaysToCompute(input.substr(i+1));
                for(auto i:res1){
                    for(auto j:res2){
                        switch(cur){
                            case '+':res.push_back(i+j); break;
                            case '-':res.push_back(i-j); break;
                            case '*':res.push_back(i*j); 
                        }
                    }
                }
            }
        }
        if(res.empty())
            res.push_back(atoi(input.c_str()));
        return res;
    }
};
