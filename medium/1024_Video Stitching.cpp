class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        // greedy
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 93.3%
        
        // Main idea:
        // Like jump game, each round maximize `end` (greedy), and set `st` to `end` after each round.
        // If `st` == `end` after a round, then there is a gap so return -1.
        sort(clips.begin(), clips.end());
        int res = 0, n = clips.size();
        for(int i = 0, st = 0, end = 0; st < T; st = end, res++) {
            for(; i < n && clips[i][0] <= st; i++) {
                end = max(end, clips[i][1]);
            }
            if(st == end) { return -1; }                // i >= n will also cause `st` == `end`
        }
        return res;
    }
};
