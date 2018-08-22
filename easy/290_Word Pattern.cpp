class Solution {
public:
    bool wordPattern(string pattern, string str) {//map_istringstream
        istringstream instr(str);
        string in;
        int patt[26]={0},i=1;
        map<string,int> mymap;
        for(char& ch:pattern){
            if(instr>>in){
                if(patt[ch-'a']!=mymap[in]) return false;
                patt[ch-'a']=mymap[in]=i;
                i++;
            }else return false;
        }
        if(instr>>in) return false;
        return true;
    }
};