class Solution {
public:
    string alienOrder(vector<string>& words) {
        // topological sort & BFS
        // 8ms, beats 99.59%
        
        // main idea:
        // Use #inDeg# to record each char's in degree, and use #pre# to record each char's successors
        // Push char whose in degree == 0 into queue, and check each queue.front() char's succ, update their in degree after poping char.
        // Check if res.length() == all distinct elements, to avoid cycle in relationship
        
        if(words.size() == 0) return "";
        unordered_map<char, int> inDeg;
        unordered_map<char, unordered_set<char>> pre;
        
        // Initialize
        for(auto& s : words) {
            for(auto& ch : s) inDeg[ch] = 0;
        }
        
        // Record indegree and insert successors of each char
        int size = words.size();
        for(int i = 0; i < size - 1; i++) {
            string cur = words[i], next = words[i + 1];
            int len = min(cur.length(), next.length());
            for(int j = 0; j < len; j++) {
                if(cur[j] != next[j]) {
                    if(pre[cur[j]].insert(next[j]).second) inDeg[next[j]]++;
                    break;
                }
            }
        }
        
        // Choose char whose in degree == 0, where we start
        string res;
        queue<char> q;
        for(auto& i : inDeg) {
            if(i.second == 0) q.push(i.first);
        }
        
        // Check and update successors of each char
        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            res += cur;
            for(auto& succ : pre[cur]) {
                if(--inDeg[succ] == 0) q.push(succ);
            }
        }
        
        // Check whether cycle exists
        return res.length() == inDeg.size() ? res : "";


        // another method, also track predecessors besides successors
        /*
        unordered_map<char,set<char>> suc,pre;
        set<char> chars;
        string fi;
        for(string se:words){
            chars.insert(se.begin(),se.end());
            for(int i=0;i<min(fi.size(),se.size());i++){   //record each pre/suc relation in map
                char f=fi[i],s=se[i];
                if(f!=s){
                    pre[s].insert(f);
                    suc[f].insert(s);
                    break;
                }
            }
            fi=se;
        }
        set<char> free=chars; 
        string res;
        for(auto p:pre) free.erase(p.first);   //#free# contains char which can directly be added into #res#
        while(free.size()){
            char tmp_fi=*free.begin();
            free.erase(tmp_fi);
            res+=tmp_fi;
            for(char tmp_se:suc[tmp_fi]){      //find its successor and modify its successor's #pre# set
                pre[tmp_se].erase(tmp_fi);
                if(pre[tmp_se].empty())        //if a char's #pre# is empty, then this char is ready to be added into #res#, so add it in #free# first
                    free.insert(tmp_se);
            }
        }
        return res.size()==chars.size()?res:"";
        */
    }
};