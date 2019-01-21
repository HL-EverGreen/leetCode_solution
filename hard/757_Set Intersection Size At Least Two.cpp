class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // intervals & greedy
        // time complexity: O(nlogn), space complexity: O(1)
        // 28ms, beats 86.9%
        
        auto comp = [](vector<int>& a, vector<int>& b) { return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]); };        // end earliest first, if end equals then range smallest first
        sort(intervals.begin(), intervals.end(), comp);
        
        int p_left = -1, p_right = -1, res = 0;
        for(auto inter : intervals) {
            if(inter[0] > p_right) {                    // not include both of the p_left and p_right
                res += 2;
                p_right = inter[1];
                p_left = p_right - 1;
            } else if(inter[0] <= p_left) continue;     // include both p_l and p_r
            else {                                      // only include p_r (p_left < inter[0] <= p_right)
                res++;
                p_left = p_right;
                p_right = inter[1];
            }
        }
        return res;
        
        // more efficient method
        /*
        vector<int> v{-1, -1};
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });
        for (auto &interval : intervals) {
            int len = v.size();
            if (interval[0] <= v[len - 2]) continue;
            if (interval[0] > v.back()) v.push_back(interval[1] - 1);
            v.push_back(interval[1]);
        }
        return v.size() - 2;
        */
    }
};