class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // graph & DFS
        // time complexity: O(n), space complexity: O(n)
        // 20ms, beats 95.21%
        
        // Main idea:
        // It is not a simple question as it required to use all ticket.
        // So we use dfs, push each station into stack,
        // when find no more next station, push it into res and pop the stack.
        // (这样可以回去把没走的环都走完，用完所有的票，只有没路走了才push进res里)
        // So we can get an vector ordered from destination to the start, reverse it and return.
        unordered_map<string, multiset<string>> m;
        for(const auto& t : tickets) {
            m[t[0]].insert(t[1]);
        }
        
        vector<string> it;
        stack<string> stk;  // stack stores current path
        
        stk.push("JFK");
        while(!stk.empty()) {
            string cur = stk.top();
            if(m[cur].empty()) {
                it.push_back(cur);      // Reach to the end, push into reversed res vector
                stk.pop();              // Remove it from current path
            } else {
                stk.push(*(m[cur].begin()));    // Record current path and delete it in set
                m[cur].erase(m[cur].begin());
            }
        }
        return vector<string>(it.rbegin(), it.rend());
    }
};