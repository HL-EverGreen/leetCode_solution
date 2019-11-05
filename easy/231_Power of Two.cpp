class Solution {
public:
    bool isPowerOfTwo(int n) {
        // bit manipulation
        // time complexity: O(1), space complexity: O(1)
        // 0ms, beats 100%
        
        // Just remove last 1 in bit representation and check whether it is 0
        if(n <= 0) return false;
        return (n & (n - 1)) == 0;

        
        // First step :) Good job haoran! 
        /*
        if(n<=0) return false;
        while(n!=1){
            if(n%2!=0) return false;
            n/=2;
        }
        return true;
        */
    }
};