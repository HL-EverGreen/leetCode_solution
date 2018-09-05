class Solution {
public:
    bool isScramble(string s1, string s2) { //partition
        if(s1==s2) return true;
        
        int len=s1.size(), same[26]={0};
        for(int i=0;i<len;i++){
            same[s1[i]-'a']++;
            same[s2[i]-'a']--;
        }
        for(int i=0;i<26;i++) if(same[i]!=0) return false;
        
        for(int i=1;i<len;i++){ //can't write like s1.substr(0,0) or s1.substr(len), because it is NULL!!!
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            if(isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i))) return true;
        }
        return false;
    }
};