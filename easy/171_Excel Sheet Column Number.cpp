class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        int temp=1;
        if(s.length()==0) return res;
        for(int i=s.length()-1;i>=0;i--){
            res+=temp*(__toascii(s[i])-64); //char to ascii
            temp*=26;
        }
        return res;
    }
};