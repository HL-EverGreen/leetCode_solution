class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // geometry & priority queue
        // time complexity: O(nlogn), space complexity: O(n)
        // 24ms, beats 99.28%
        
        // Main idea:
        // Use priority queue to keep current hightest height and end pos.

        vector<vector<int>> res;
        int cur = 0, cur_X, cur_H, len = buildings.size();
        priority_queue<pair<int, int>> liveBlg;      // pair: <height, end pos>
        while(cur < len || !liveBlg.empty()) { 
            // If existed current building, set cur_X to its end pos. Otherwise set cur_X to next building start pos.
            cur_X = liveBlg.empty() ? buildings[cur][0] : liveBlg.top().second;
            
            // If next building starts after current building ends, can pop building ends before current
            // build with lower height, because these building won't contribute critical points anymore
            if(cur >= len || buildings[cur][0] > cur_X) {
                while(!liveBlg.empty() && (liveBlg.top().second <= cur_X)) { 
                    liveBlg.pop(); 
                }
            } 

            // If next building starts before current building ends, push new buildings into priority queue
            else {
                cur_X = buildings[cur][0];
                // Push all new buildings start at the same pos
                while(cur < len && buildings[cur][0] == cur_X) {
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            
            // Set height to the topest building's height
            cur_H = liveBlg.empty() ? 0 : liveBlg.top().first;
            if(res.empty() || (res.back()[1] != cur_H) ) res.push_back({cur_X, cur_H});
        }
        return res;
    }
};