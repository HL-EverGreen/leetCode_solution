class Solution {
public:
    string nextClosestTime(string time) {
        // string
        // time complexity: O(1), space complexity: O(1)
        // 0ms, beats 100%
        
        // check each possibilities
        int unit[4] = {600, 60, 10, 1};
        int pos = time.find(':'), cur = stoi(time.substr(0, pos)) * 60 + stoi(time.substr(pos + 1));
        string next = "0000";
        for(int i = 1, d = 0; i <= 1440 && d < 4; i++) {
            int t = (cur + i) % 1440;
            for(d = 0; d < 4; d++) {
                next[d] = '0' + t / unit[d];
                t %= unit[d];
                if(time.find(next[d]) == string::npos) { break; }
            }
        }
        return next.substr(0, 2) + ':' + next.substr(2);
    }
};