class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        // array & greedy
        // time complexity: O(n), space complexity: O(1)
        // 52ms, beats 96.86%
        
        // Main idea:
        // Use last index to record last attack time, and at each attack time add
        // need added duration before current time stamp
        int n = timeSeries.size(), res = 0;
        if(n < 1) { return res; }
        for(int i = 1; i < n; i++) {
            res += min(timeSeries[i] - timeSeries[i - 1], duration);
        }
        res += duration;
        return res;
    }
};