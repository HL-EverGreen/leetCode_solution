class Solution {
public:
    /*
    bool validTree(int n, vector<pair<int, int>>& edges) {//dfs
        if(edges.size()!=n-1) return false;
        vector<bool> isVisited(n,false);
        vector<vector<int>> graph(n);
        for(auto e:edges){
            graph[e.first].push_back(e.second);
            graph[e.second].push_back(e.first);
        }
        dfs(graph,isVisited,0);
        for(auto i:isVisited)
            if(!i) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& graph, vector<bool>& isVisited, int node){// Should be vector<vector<int>>& graph rather than <vector<vector<int>> graph
                                                                            //Otherwise memory would exceed the limit(use & to transfer the address)
        if(isVisited[node]) return;
        isVisited[node]=true;
        for(int num:graph[node])
            dfs(graph,isVisited,num);
    }
    */
    
    bool validTree(int n, vector<pair<int, int>>& edges) {//find two nums' topest parent, a general way to detect circle
        vector<int> num(n);
        for(int i=0;i<n;i++) num[i]=i;
        for(auto e:edges){         //determine if there exists circle
            int f=e.first;
            int s=e.second;
            while(f!=num[f]) f=num[f]; //to find the topest parent
            while(s!=num[s]) s=num[s]; 
            if(f==s) return false;     //if two nums' topest parent are the same, then there exists a circle
            num[s]=f;
        }
        return edges.size()==n-1;  //determine every node is connected
    }
};