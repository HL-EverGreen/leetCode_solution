class Solution {
public:
    string convertToTitle(int n) { //digit trans
        //recursive solution
        return n==0?"":convertToTitle(n/26)+(char)(--n%26+'A'); //看起来--n比convertToTitle(n/26)先执行
        
        //iteration solution
        /*
        string res="";
        while(n/26){
            int rem=--n%26;
            res=char('A'+rem)+res;
            n/=26;
        }
        if(n>0) res=char('A'+n-1)+res;
        return res;
        */
    }
};