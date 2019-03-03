class Solution {
public:
    // BFS & DFS & graph
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // method 1:
        // BFS
        // time complexity: O(n^2), space complexity: O(n)
        // 20ms, beats 100%
        
        // main idea:
        // Use queue to store nodes whose in degree is 0
        // When pop queue's top, check its successor (in vector<unordered_set<int>>), and reduce their in degree by 1. 
        // If some's in degree becomes 0, push it in queue
        // Check number of nodes in total being pushed in queue, whether == numCourses

        vector<unordered_set<int>> pre(numCourses);
        vector<int> inDeg(numCourses);
        for(auto& p : prerequisites) {                  // construct relationship
            pre[p.first].insert(p.second);
            inDeg[p.second]++;
        }
        
        queue<int> q;
        int num = 0;
        for(int i = 0; i < numCourses; i++) {           // push nodes with 0 in-degree into queue
            if(inDeg[i] == 0) {
                q.push(i);
                num++;
            }
        }
        
        while(!q.empty()) {                             // continue check successor for nodes in queue
            int cur = q.front();
            q.pop();
            for(auto& i : pre[cur]) {
                if(--inDeg[i] == 0) {
                    q.push(i);
                    num++;
                }
            }
        }
        return num == numCourses;
    }

    // method 2:
    // DFS
    // main idea: detect if there exists a cycle. If exists, then can't schedule courses
    /*
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
                return false;
        return true;
    }
    
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    } 
    
    bool dfs_cycle(vector<unordered_set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
                return true;
        return onpath[node] = false;
    }
    */


    // Another kind of BFS, use array

    // BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. 
    // If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we have found one. 
    // We set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of all its neighbors by 1. 
    // This process will be repeated for n (number of nodes) times. If we have not returned false, we will return true.
    /*
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph=make_graph(numCourses,prerequisites);
        vector<int> degrees=get_degree(numCourses,graph);
        for(int i=0;i<numCourses;i++){
            int j=0;
            for(;j<numCourses;j++)
                if(!degrees[j]) break;
            if(j==numCourses) return false;
            degrees[j]=-1;
            for(auto el:graph[j]) degrees[el]--;
        }
        return true;
    }
    
private:
    vector<unordered_set<int>> make_graph(int num, vector<pair<int,int>>& pre){
        vector<unordered_set<int>> graph(num);
        for(auto p:pre) graph[p.second].insert(p.first);
        return graph;
    }
    
    vector<int> get_degree(int num, vector<unordered_set<int>>& graph){
        vector<int> degrees(num,0);
        int g_size=graph.size();
        for(auto set:graph)
            for(auto el:set)
                degrees[el]++;
        return degrees;
    }
    */
};
        
        //can only detect circle in undirected graph
        //CANT use in DIRECTED graph!!!
        /*
        vector<int> cir;
        for(int i=0;i<numCourses;i++) cir.push_back(i);
        int size=prerequisites.size();
        for(int i=0;i<size;i++){
            int hi=prerequisites[i].first,lo=prerequisites[i].second;
            while(cir[lo]!=lo) lo=cir[lo];
            while(cir[hi]!=hi) hi=cir[hi];
            if(lo==hi) return false;
            cir[lo]=hi;
        }
        return true;
        */