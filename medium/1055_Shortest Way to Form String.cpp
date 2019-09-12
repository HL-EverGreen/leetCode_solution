class Solution {
public:
    int shortestWay(string source, string target) {
        // greedy

        // method 1
        // greedy & string
        // time complexity: O(mn), space complexity: O(1)
        // 0ms, beats 100%
        
        int n = source.size();
        int res = 0;
        for(int ti = 0, si = 0; ti < target.size();) {
            while(si < n && source[si] != target[ti]) ++si;     // Not fount current char
            if(si < n) ++si, ++ti;  // Successfully match
            else {      // No match, start new round
                if(++res > ti) return -1;
                si = 0;
            }
        }
        return res + 1;    // + 1 for initial round
        

        // method 2
        // greedy
        // time complexity: O(m + n), space complexity: O(m)
        
        // Main idea:
        // Since in previous solution, we need to find next occurence of target[ti] in source.
        // And we use +1 to find, it is time-consuming, we could record the next ch occurence index after current index using data structure.
        // dict[i][j] present the first occurence of 'a' + j after index i (>= i) in source
        
        int m = source.size();
        vector<vector<int>> dict(m, vector<int>(26, -1));
        dict[m - 1][source[m - 1] - 'a'] = m - 1;
        
        // Construct index table
        // Time complexity: O(m)
        for(int i = m - 2; i >= 0; --i) {
            dict[i] = dict[i + 1];
            dict[i][source[i] - 'a'] = i;
        }
        
        // Time complexity: O(n)
        int idx = 0, res = 0;
        for(char t : target) {
            if(dict[0][t - 'a'] == -1) return -1;   // Not present in whole `source`
            
            if(dict[idx][t - 'a'] == -1) {          // Not present in remaining `source`, start new round
                idx = 0;
                ++res;
            } 
            
            idx = dict[idx][t - 'a'] + 1;
            
            if(idx == m) {      // Reach at the end of `source`, start new round
                idx = 0;
                ++res;
            }
        }
        return idx > 0 ? res + 1 : res; // If additional round needed (current in new round)
    }
};