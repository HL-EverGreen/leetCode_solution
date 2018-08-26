class Solution {
public:
    int lengthOfLastWord(string s) {//string
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