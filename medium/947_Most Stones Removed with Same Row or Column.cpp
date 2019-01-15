class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // union find & DFS
        // 32ms, beats 83.19%
        
        // DFS can also solve this problem in the same way as Number of Islands

        // union find method
        // use union find to group stones into different groups (analogy to an island), then the maximum number of remove operations could be stones number - island number
        unordered_map<int, int> stone;
        int group = 0;
        
        for(int i = 0; i < stones.size(); i++) {
            unionStone(stone, group, stones[i][0], ~stones[i][1]);        // use ~ to distinguish col index from row index
        }
        return stones.size() - group;
    }
    
    int find(unordered_map<int, int>& stone, int& group, int idx) {       // connect all stone into different groups, each stone in same group has same stone[idx]
        if(stone.find(idx) == stone.end()) {
            stone[idx] = idx;
            group++;
        }
        if(idx != stone[idx]) {
            stone[idx] = find(stone, group, stone[idx]);
        }
        return stone[idx];
    }

    void unionStone(unordered_map<int, int>& stone, int& group, int row, int col) {
        row = find(stone, group, row);
        col = find(stone, group, col);
        if(row != col) {                // a stone connect its row and col index
            stone[row] = col;
            group--;
        }
    }
};