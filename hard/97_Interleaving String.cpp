class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) { //dp
        //DP table represents if s3 is interleaving at (i+j)th position when s1 is at ith position, and s2 is at jth position.           
        //0th position means empty string.

        if(s1.length()+s2.length()!=s3.length()) return false;
        bool table[s1.length()+1][s2.length()+1]={false};
        table[0][0]=true;
        for(int i=0;i<s1.length()+1;i++)
            for(int j=0;j<s2.length()+1;j++){
                if(i==0 && j>0) table[i][j]=(table[i][j-1] && s2[j-1]==s3[i+j-1]);
                else if(j==0 && i>0) table[i][j]=(table[i-1][j] && s1[i-1]==s3[i+j-1]);
                else if(i>0 &&j>0) table[i][j]=(table[i-1][j] && s1[i-1]==s3[i+j-1]) || (table[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        return table[s1.length()][s2.length()];
    }
};