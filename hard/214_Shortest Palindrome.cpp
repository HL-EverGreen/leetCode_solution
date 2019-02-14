class Solution {
public:
    string shortestPalindrome(string s) {
        // KMP && palindrome
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 100%
        
        // We can construct the following string and run KMP algorithm on it: 
        // (s) + (some symbol not present in s) + (reversed string)
        // After running KMP on that string as result we get a vector p with values of a prefix function for each character 
        // (for definition of a prefix function see KMP algorithm description). 
        // We are only interested in the last value because it shows us the largest suffix of the reversed string 
        // that matches the prefix of the original string. So basically all we left to do is to add the first k characters 
        // of the reversed string to the original string, where k is a difference between original string size and 
        // the prefix function for the last character of a constructed string.

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