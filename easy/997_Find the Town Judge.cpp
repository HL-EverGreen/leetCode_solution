class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 160ms, beats 90%
        
        // Main idea:
        // Use two vector to record trustee and truster's number
        
        vector<int> trusted(N + 1), truster(N + 1);
        
        /* Record the relationship */
        for(auto t : trust) {
            trusted[t[1]]++;
            truster[t[0]]++;
        }
        
        /* Find judge */
        for(int i = 1; i <= N; i++) {
            if(trusted[i] == N - 1 && truster[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};