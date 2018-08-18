class Solution {
public:
    string addBinary(string a, string b) {//bit operation
        string res="";
        int c=0,index_a=a.size()-1,index_b=b.size()-1;
        while(index_a>=0 || index_b>=0 || c==1){
            c+=index_a>=0?a[index_a--]-'0':0;
            c+=index_b>=0?b[index_b--]-'0':0;
            res=char(c % 2 + '0') + res;
            c/=2;
        }
        return res;
    }
};