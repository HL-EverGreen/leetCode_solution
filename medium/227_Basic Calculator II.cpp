class Solution {
public:
    int calculate(string s) { //calculator
        istringstream in('+'+s+'+');
        long long term=0,n=0,total=0;
        char op;
        while(in>>op){
            if(op=='+' || op=='-'){
                total+=term;
                in>>term;
                term*=(op=='+'?1:-1);
            }else{
                in>>n;
                if(op=='*') term*=n;
                else term/=n;
            }
        }
        return total;
    }
};