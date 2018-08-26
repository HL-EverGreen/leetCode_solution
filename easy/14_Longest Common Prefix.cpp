class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//vector_string
        int s_size=strs.size(),count=0;
        string res;
        char tmp;
        if(s_size==0) return res;
        if(s_size==1) return strs[0];
        while(count<strs[0].size()){
            tmp=strs[0][count];
            for(int i=1;i<s_size;i++){
                if(count>=strs[i].size() || tmp!=strs[i][count]) return res;
            }
            res+=tmp;
            count++;
        }
        return res;
    }
};