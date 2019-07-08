class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        // sliding window
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Use single index `start` to start a slide window.
        // Each time add one new elem in window and delete one if exceed window size
        int cnt[26] = {0}, dup = 0, res = 0, size = S.length();
        for(int start = 0; start < size; start++) {
            if(++cnt[S[start] - 'a'] == 2) dup++;
            if(start + 1 >= K) {                                // If has K elements in window
                if(!dup) res++;
                if(--cnt[S[start + 1 - K] - 'a'] == 1) dup--;
            }
        }
        return res;
    }
};