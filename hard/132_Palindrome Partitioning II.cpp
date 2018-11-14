class Solution {
public:
    int minCut(string s) {
        //dp
        //time complexity: O(n^2)
        //isPalin[i][j] means whether string s[i]...s[j] is palindrome
        //minCut[i] means minimum number of cut needed to divide string s[0]...s[i-1] into all palindrome words
        
        int s_size = s.length();
        if(s_size <= 1) return 0;
        
        bool isPalin[s_size][s_size];
        fill_n(&isPalin[0][0], s_size * s_size, false);
        
        int minCut[s_size + 1];
        for(int idx = 0; idx <= s_size; idx++){
            minCut[idx] = idx - 1;
        }
        
        for(int j = 1; j < s_size; j++){
            for(int i = j; i >= 0; i--){
                if(s[j] == s[i] && (j - i < 2 || isPalin[i + 1][j - 1])){
                    isPalin[i][j] = true;
                    minCut[j + 1] = min(minCut[j + 1], 1 + minCut[i]);
                }
            }
        }
        return minCut[s_size];
    }
};