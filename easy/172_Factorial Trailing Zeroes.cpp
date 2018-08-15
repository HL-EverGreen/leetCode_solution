class Solution {
public:
    int trailingZeroes(int n) { // count the number of factor 5
        int res=0;
        for(long long i=5;n/i>0;i*=5){
            res+=n/i;
        }
        return res;
    }
};