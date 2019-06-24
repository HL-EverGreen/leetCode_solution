class Solution {
public:
    string pushDominoes(string dominoes) {
        // string & two pointers
        // time complexity: O(n), space complexity: O(1)
        // 24ms, beats 88.67%
        
        // Main idea:
        // i present last non '.' char's pos, use j to skip '.' char.
        // When j is non '.' char, compare s[i] and s[j]:
        // 1) if s[i] and s[j] are same, fill all mid pos with s[i]
        // 2) if s[i] == 'L' and s[j] == 'R', fill all with '.'
        // 3) if s[i] == 'R' and s[j] == 'L', half half, and one '.' if necessary
        dominoes = 'L' + dominoes + 'R';
        string res;
        int n = dominoes.size();

        for(int i = 0, j = 1; j < n; j++) {
            if(dominoes[j] == '.') { continue; }        // Skip all '.'
            int mid_len = j - i - 1;
            if(i > 0) { res += dominoes[i]; }           // Add start index

            if(dominoes[i] == dominoes[j]) { 
                res += string(mid_len, dominoes[i]);
            } else if(dominoes[i] == 'L' && dominoes[j] == 'R') {
                res += string(mid_len, '.');
            } else {
                res += string(mid_len / 2, 'R') + string(mid_len % 2, '.') + string(mid_len / 2, 'L');
            }
            i = j;                                      // Update i to last non '.' index
        }
        return res;
    }
};