class Solution {
public:
    string getHint(string secret, string guess) {//string
        int a=0,b=0;
        if(secret.size()!=guess.size() || secret.empty()) return "0A0B";
        vector<int> num_s(10,0),num_g(10,0);
        //int num_s[10]={0},num_g[10]={0};
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) ++a;
            else{
                ++num_s[secret[i]-'0'];
                ++num_g[guess[i]-'0'];
            }
        }
        
        for(int i=0;i<num_s.size();i++){
            b+=min(num_s[i],num_g[i]);
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};