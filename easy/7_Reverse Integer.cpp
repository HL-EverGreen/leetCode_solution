class Solution {
public:
    int reverse(int x) {
        //reverse number with checking overflow
        //time complexity: O(n), n is the number of digits contained in x
        
        int res = 0, temp = 0;
        while(x){
            res = 10 * temp + x % 10;
            
            //check if overflow
            if(res / 10 != temp){
                return 0;
            }
            
            temp = res;
            x /= 10;
        }
        return res;
    }
};