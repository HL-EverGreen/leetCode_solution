class Solution {
public:
    double myPow(double x, int n) { //power
        double ans=1;
        unsigned long long pow;
        if(n<0){
            pow=-n;
            x=1/x;
        }else pow=n;
        while(pow){
            if(pow&1) ans*=x;
            x*=x;
            pow>>=1;
        }
        return ans;
    }
};