class Solution {
public:
    string shortestPalindrome(string s) {
        // KMP && palindrome
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 100%
        
        // We can construct the following string and run KMP algorithm on it: 
        // (s) + (some symbol not present in s) + (reversed string)
        // After running KMP on that string as result we get a vector p with values of a prefix function for each character。
        // We are only interested in the last value because it shows us the largest suffix of the reversed string 
        //   that matches the prefix of the original string. So basically all we left to do is to add the first k characters 
        //   of the reversed string to the original string, where k is a difference between original string size and 
        //   the prefix function for the last character of a constructed string.

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string temp = s + "#" + rev_s;
        vector<int> p(temp.size(), 0);
        
        for(int i = 1; i < temp.size(); i++) {
            int j = p[i - 1];
            while(j > 0 && temp[i] != temp[j]) j = p[j - 1];
            p[i] = (j += temp[i] == temp[j]);
        }
        return rev_s.substr(0, s.size() - p[temp.size() - 1]) + s;
    }
};

// BETTER EXPLAIN!!!
// https://leetcode.com/problems/shortest-palindrome/discuss/60113/Clean-KMP-solution-with-super-detailed-explanation
// code in Java:
public String shortestPalindrome(String s) {
    String temp = s + "#" + new StringBuilder(s).reverse().toString();
    int[] table = getTable(temp);
    
    //get the maximum palin part in s starts from 0
    return new StringBuilder(s.substring(table[table.length - 1])).reverse().toString() + s;
}

public int[] getTable(String s){
    //get lookup table
    int[] table = new int[s.length()];
    
    //pointer that points to matched char in prefix part
    
    int index = 0;
    //skip index 0, we will not match a string with itself
    for(int i = 1; i < s.length(); i++){
        if(s.charAt(index) == s.charAt(i)){
            //we can extend match in prefix and postfix
            table[i] = table[i-1] + 1;
            index ++;
        }else{
            //match failed, we try to match a shorter substring
            
            //by assigning index to table[i-1], we will shorten the match string length, and jump to the 
            //prefix part that we used to match postfix ended at i - 1
            index = table[i-1];
            
            while(index > 0 && s.charAt(index) != s.charAt(i)){
                //we will try to shorten the match string length until we revert to the beginning of match (index 1)
                index = table[index-1];
            }
            
            //when we are here may either found a match char or we reach the boundary and still no luck
            //so we need check char match
            if(s.charAt(index) == s.charAt(i)){
                //if match, then extend one char 
                index ++ ;
            }
            
            table[i] = index;
        }
        
    }
    
    return table;
}