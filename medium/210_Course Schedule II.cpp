class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {//bfs
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