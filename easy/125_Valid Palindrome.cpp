class Solution {
public:
    bool isPalindrome(string s) { //string
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            while(!isalnum(s[i]) && i<j) i++;   //determine if is alphanumeric
            while(!isalnum(s[j]) && i<j) j--;
            if(toupper(s[i])!=toupper(s[j])) return false;   //change to uppercase first
        }
        return true;
    }
};