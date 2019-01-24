class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        // array & greedy
        // 180ms, beats 10.12%
        
        // find substr of stamp and replace with '*', then find something like *ad ...
        vector<int> res;
        int total_stamp = 0, cur_stamp = 1;
        while(cur_stamp) {                      // find until no more stamp can be placed
            cur_stamp = 0;
            for(int sz = stamp.length(); sz > 0; sz--) {
                for(int i = 0; i <= stamp.length() - sz; i++) {
                    string new_stamp = string(i, '*') + stamp.substr(i, sz) + string(stamp.length() - i - sz, '*');
                    auto pos = target.find(new_stamp);
                    while(pos != string::npos) {
                        res.push_back(pos);
                        cur_stamp += sz;
                        fill(target.begin() + pos, target.begin() + pos + stamp.length(), '*');
                        pos = target.find(new_stamp);
                    }
                }
            }
            total_stamp += cur_stamp;
        }
        reverse(res.begin(), res.end());
        return total_stamp == target.size() ? res : vector<int>();      // if replace all characters in target
    }
};