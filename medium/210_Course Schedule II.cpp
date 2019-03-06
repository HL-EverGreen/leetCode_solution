class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // topological sort
        // time complexity: O(n^2), actually O(n), space complexity: O(n)
        // 24ms, beats 92.75%
        
        // main idea:
        // Use queue to store nodes whose in degree is 0
        // When pop queue's top, check its successor (in vector<unordered_set<int>>), and reduce their in degree by 1. 
        // If some's in degree becomes 0, push it in queue
        // Check number of nodes in total being pushed in queue, whether == numCourses
        vector<int> count(numCourses, 0);
        vector<unordered_set<int>> pre(numCourses);
        for(auto& p : prerequisites) {
            if(pre[p.second].insert(p.first).second) count[p.first]++;
        }
        
        queue<int> q;
        vector<int> res;
        for(int i = 0; i < numCourses; i++) {
            if(count[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for(auto& succ : pre[cur]) {
                if(--count[succ] == 0) q.push(succ);
            }
        }
        
        if(res.size() == numCourses) return res;
        else return {};
    }

    
    // BFS
    /*
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph=makeGraph(numCourses,prerequisites);
        vector<int> degrees=getDegree(numCourses,graph);
        vector<int> res;
        queue<int> next;
        for(int i=0;i<numCourses;i++)
            if(!degrees[i]) next.push(i); //find node with enter-degree==0 
        for(int i=0;i<numCourses;i++){
            if(next.empty()) return {}; //detect circle in graph
            int tmp=next.front();
            next.pop();
            res.push_back(tmp);
            for(auto e:graph[tmp]){
                if(!--degrees[e]) next.push(e);
            }
        }
        return res;
    }
    
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int,int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto p:prerequisites){
            graph[p.second].insert(p.first);
        }
        return graph;
    }
    
    vector<int> getDegree(int numCourses, vector<unordered_set<int>>& graph){
        vector<int> degrees(numCourses,0);
        for(auto g:graph)
            for(auto elem:g)
                degrees[elem]++;
        return degrees;
    }
    */


    //DFS
    /*
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> toposort;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
                return {};
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }

    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }

    bool dfs(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) { 
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
                return true;
        toposort.push_back(node);
        return onpath[node] = false;
    }
    */
};