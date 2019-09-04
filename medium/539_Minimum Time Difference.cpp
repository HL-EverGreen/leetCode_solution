class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // bucket sort
        // time complexity: O(n), space complexity: O(1440)
        // 8ms, beats 99.77%
        
        // Main idea:
        // First loop to record all timestamp in array.
        // Second loop to find the minimum difference.
        
        // *Since exists duplicate timestamp, and 1440 is very large, so directly using sort and compare
        //   one by one may not be a bad idea. Time complexity: O(nlogn)
        
        bool ts[24 * 60];
        memset(ts, false, sizeof(ts));
        
        for(auto time : timePoints) {
            int idx = parseTimeStamp(time);
            if(ts[idx]) return 0;           // Exists duplicate timestamp
            ts[idx] = true;
        }
        
        int res = 1440;
        int start_pos = -1;
        int last = -1;
        
        for(int i = 0; i < 1440; ++i) {
            if(ts[i]) {
                if(start_pos == -1) {
                    start_pos = i;
                } else res = min(res, i - last);
                last = i;
            }
            res = min(res, start_pos + 1440 - last);        // Difference btw smallest and biggest timestamp
        }
        return res;
    }
    
    /* Transform timestamp into integer */
    int parseTimeStamp(string ts) {
        int pos = ts.find(':');
        return stoi(ts.substr(0, pos)) * 60 + stoi(ts.substr(pos + 1));
    }
};