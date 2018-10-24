class Solution {
public:
    bool isPalindrome(int x) { //int palindrome
        //reverse the input x and compare
        if(x < 0) return false;
        int old = x, reverse = 0;
        while(x > 0){
            reverse = 10 * reverse + x % 10;
            x /= 10;
        }
        return reverse == old;
        
        //reverse the second half and compare
        /*
        if(x < 0 || (x != 0 && x % 10 == 0)) return false;
        int sum = 0;
        while(x > sum){
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return x == sum || x == sum / 10;
        */

        //use to_string
        /*
        if(x<0) return false;
        string num=to_string(x);
        int left=0,right=num.length()-1;
        while(left<right){
            if(num[left]!=num[right]) return false;
            left++;
            right--;
        }
        return true;
        */
    }
};