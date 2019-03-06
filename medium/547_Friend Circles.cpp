class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        // DFS & BFS
        // 24ms, beats 98.65%
        // can also use Union find
        
        // main idea:
        // When encounter unvisited node, res++, then do DFS/BFS to visit all friends in its friend circle
        // Just like number of island
        
        int n = M.size(), res = 0;
        if(n < 1) return 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                res++;
                findCircle(M, visited, i);
            }
        }
        return res;
    }
    
    // DFS
    void findCircle(vector<vector<int>>& M, vector<bool>& visited, int i) {
        visited[i] = true;
        for(int j = 0; j < M.size(); j++) {
            if(M[i][j] && !visited[j]) findCircle(M, visited, j);
        }
    }


    // method 2
    // Union Find
    /*
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        vector<int> leads(n, 0);
        for (int i = 0; i < n; i++) { leads[i] = i; }   // initialize leads for every kid as themselves

        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {   // avoid recalculate M[i][j], M[j][i]
                if (M[i][j]) {
                    int lead1 = find(i, leads);
                    int lead2 = find(j, leads);
                    if (lead1 != lead2) {       // if 2 group belongs 2 different leads, merge 2 group to 1
                        leads[lead1] = lead2;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }

    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }
    */
};