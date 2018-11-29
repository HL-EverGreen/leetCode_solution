class Solution {
public:
    void reverseWords(string &s) {
        // istringstream
        // time complexity: O(n), n is the number of the words
        // 4ms beats 98.93%
        
        istringstream sin(s);
        sin >> s;
        string temp;
        while(sin >> temp) { s = temp + " " + s; }
        
        // is s is empty string
        if(s[0] == ' ') { s = ""; }
    }
};
