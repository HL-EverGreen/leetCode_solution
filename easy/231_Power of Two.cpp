class Solution {
public:
    bool isPowerOfTwo(int n) {
        //or use bit operation
        //return ( n > 0 && ( n & ( n - 1 ) ) == 0 );
        
        if(n<=0) return false;
        while(n!=1){
            if(n%2!=0) return false;
            n/=2;
        }
        return true;
    }
};