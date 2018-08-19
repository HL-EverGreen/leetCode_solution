class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {//bit_operation
        //the main idea is to find the same number array in the left part of both the M and N bit array
        int mask=UINT_MAX; //1111...11111
        while((m&mask)!=(n&mask)){
            mask<<=1; //1111...11110
        }
        return m&mask;
        
        //same main idea
        //return n>m?rangeBitwiseAnd(m/2,n/2)<<1:m;
    }
};