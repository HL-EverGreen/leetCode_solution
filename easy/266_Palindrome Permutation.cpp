class Solution {
public:
    bool canPermutePalindrome(string s) {
        map<char,int> myMap;
        for(int i=0;i<s.length();i++){
            if(myMap.find(s[i])!=myMap.end())
                myMap[s[i]]+=1;
            else myMap[s[i]]=1;
        }
        int res=0;
        //if palindrome, odd number won't exceed 1
        map<char,int>::iterator iter;
        for(iter=myMap.begin();iter!=myMap.end();iter++)
            if(iter->second%2==1)
                res++;
        return res<=1;
    }
};