class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // BFS & Bi-BFS
        // Bi-BFS main idea:
        // Use q1 and q2 to represent each search queue, since that q1 and q2 shares the
        // same visited set, so only can put `if(q2.find(ne) != q2.end()) { return res + 1; }`
        // when find next string.


        // Method 1:
        // BFS
        // 332ms, beats 22.85%
        /*
        unordered_set<string> visited;
        unordered_set<string> dds(deadends.begin(), deadends.end());
        queue<string> q;
        int res = -1;
        if(dds.find("0000") != dds.end()) { return res; }
        visited.insert("0000");
        q.push("0000");
        
        while(!q.empty()) {
            res++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string cur = q.front();
                q.pop();
                if(cur == target) { return res; }
                vector<string> next = findNext(cur);
                for(auto s : next) {
                    if(dds.find(s) == dds.end() && visited.find(s) == visited.end()) {
                        visited.insert(s);
                        q.push(s);
                    }
                }
            }
        }
        return -1;
        */

        // Method 2
        // Bi-BFS
        // 52ms, beats 92.93%
        unordered_set<string> dds(deadends.begin(), deadends.end());
        unordered_set<string> q1, q2, pass, visited;
        if(dds.find("0000") != dds.end()) { return -1; }
        int res = 0;
        visited.insert("0000");
        q1.insert("0000");
        q2.insert(target);
        while(!q1.empty() && !q2.empty()) {
            if(q1.size() > q2.size()) { swap(q1, q2); }
            pass.clear();
            for(auto cur : q1) {
                vector<string> next = findNext(cur);
                for(auto ne : next) {
                    if(q2.find(ne) != q2.end()) { return res + 1; }
                    if(visited.find(ne) != visited.end()) { continue; }
                    if(dds.find(ne) == dds.end()) {
                        pass.insert(ne);
                        visited.insert(ne);    
                    }
                }
            }
            swap(q1, pass);
            res++;
        }
        return -1;
    }
    
    
    
    vector<string> findNext(string cur) {
        vector<string> next;
        for(int j = 0; j < 4; j++) {
            string tmp = cur;
            tmp[j] = (cur[j] - '0' + 1) % 10 + '0';
            next.push_back(tmp);
            tmp[j] = (cur[j] - '0' + 9) % 10 + '0';
            next.push_back(tmp);
        }
        return next;
    }
};