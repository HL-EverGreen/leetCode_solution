class Solution {
    //dfs
    
    //For DFS, it will first visit a node, then one neighbor of it, then one neighbor of this neighbor... and so on. 
    //If it meets a node which was visited in the current process of DFS visit, a cycle is detected and we will return false.
    //Otherwise it will start from another unvisited node and repeat this process till all the nodes have been visited. 
    //Note that you should make two records: one is to record all the visited nodes and the other 
    //is to record the visited nodes in the current DFS visit.

    //The code is as follows. We use a vector<bool> visited to record all the visited nodes and another vector<bool> onpath 
    //to record the visited nodes of the current DFS visit. Once the current visit is finished, we reset the onpath value 
    //of the starting node to false.
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
    
    //bfs
    //BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. 
    //If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we have found one. 
    //We set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of all its neighbors by 1. 
    //This process will be repeated for n (number of nodes) times. If we have not returned false, we will return true.
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