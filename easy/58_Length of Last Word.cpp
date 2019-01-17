class Solution {
public:
    int lengthOfLastWord(string s) {
        // string
        // time complexity: O(n), space complexity: O(1)
        
        // method 1: using stringstream
        // 4ms, beats 93.28%
        istringstream sin(s);
        string word;
        while(sin >> word);
        return word.length();

        // method 2: visit from back to front
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        /*
        int s_size=s.size(), count=0;
        bool find_word=false;
        for(int i=s_size-1;i>=0;i--){
            if(s[i]!=' ') {
                find_word=true;
                count++;
            }
            if(find_word && s[i]==' ')
                return count;
        }
        return count;
        */

        //a more simple solution
        /*
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
        */
    }
};