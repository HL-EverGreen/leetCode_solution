class Solution {
public:
    string alienOrder(vector<string>& words) { //pre_succ_legal_order
        unordered_map<char,set<char>> suc,pre;
        set<char> chars;
        string fi;
        for(string se:words){
            chars.insert(se.begin(),se.end());
            for(int i=0;i<min(fi.size(),se.size());i++){   //record each pre/suc relation in map
                char f=fi[i],s=se[i];
                if(f!=s){
                    pre[s].insert(f);
                    suc[f].insert(s);
                    break;
                }
            }
            fi=se;
        }
        set<char> free=chars; 
        string res;
        for(auto p:pre) free.erase(p.first);   //#free# contains char which can directly be added into #res#
        while(free.size()){
            char tmp_fi=*free.begin();
            free.erase(tmp_fi);
            res+=tmp_fi;
            for(char tmp_se:suc[tmp_fi]){      //find its successor and modify its successor's #pre# set
                pre[tmp_se].erase(tmp_fi);
                if(pre[tmp_se].empty())        //if a char's #pre# is empty, then this char is ready to be added into #res#, so add it in #free# first
                    free.insert(tmp_se);
            }
        }
        return res.size()==chars.size()?res:"";
    }
};