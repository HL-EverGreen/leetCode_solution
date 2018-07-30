class Solution {
public:
    int hammingWeight(uint32_t n) {//bit operation
        int res=0;
        while(n){//every & operation delete one '1' bit from the number. e.g. 1010110&(1010110-1)=1010110&1010101=1010100
            n&=n-1;
            res++;
        }
        return res;
        
        //another solution using bitset
        //return bitset<32>(n).count();

        //about bitset: https://www.cnblogs.com/magisk/p/8809922.html
    }
};