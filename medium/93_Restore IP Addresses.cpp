class Solution {
public:
    vector<string> restoreIpAddresses(string s) {//dfs
        vector<string> res;
        string ip;
        dfs(s,ip,res,0,0);
        return res;
    }
    
    void dfs(string s, string ip, vector<string>& res, int start, int step){
        if(start==s.size() && step==4){
            ip.erase(ip.end()-1); //remove the last '.' from the last decimal number
            res.push_back(ip);
            return;
        }
        if(s.size()-start>(4-step)*3) return;
        if(s.size()-start<(4-step)) return;
        int num=0;
        for(int i=start;i<start+3;i++){
            num=num*10+(s[i]-'0');
            if(num<=255){
                ip+=s[i];
                dfs(s,ip+'.',res,i+1,step+1);
            }
            if(num==0) break;
        }
    }
};