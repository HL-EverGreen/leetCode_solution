class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // union find
        // time complexity: O(ElogE), space complexity: O(n)
        // 136ms, beats 53.55%
        
        // Main idea:
        // Since # of house are in range [1, n], so we can assume there is house 0 where hidden well exists.
        // So wells[i] can be regarded as pipe fee from house 0 and house i.
        // So the problem is converted into find MST of the n node plus house 0
        // We use greedy algorithm to find next pipe candidate, and add this candidate
        // only if it can connect two seperate union (using union find to record)
        // All in all, the main idea is:
        //   1) Merge all costs of pipes together and sort by key.
        //   2) Greedily lay the pipes if it can connect two seperate union.
        //   3) Appply union find to record which houses are connected.
        
        uf.resize(n + 1, 0);
        for(auto& p : pipes) swap(p[0], p[2]);      // {price, house1, house2}
        for(int i = 0; i < n; ++i) {
            uf[i + 1] = i + 1;
            pipes.push_back({wells[i], 0, i + 1});  // Price connect to house 0 (transfromed by well[i])
        }
        
        sort(pipes.begin(), pipes.end());
        
        int res = 0;
        for(int i = 0; n > 0; ++i) {
            int x = find(pipes[i][1]), y = find(pipes[i][2]);
            if(x != y) {                            // Only add pipe if it can connect two seperate unions
                res += pipes[i][0];
                uf[x] = y;
                --n;
            }
        }
        return res;
    }

private:
    vector<int> uf;
    int find(int x) {
        if(x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};
