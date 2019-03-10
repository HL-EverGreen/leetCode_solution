class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // BFS
        // 28ms, beats 66.82%
        
        // main idea:
        // Use hash map to record each block's id and minimum step required to move to this block
        
        int n = board.size();
        unordered_map<int, int> step;
        step[1] = 0;
        queue<int> q;
        q.push(1);
        
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            if(cur == n * n) return step[cur];

            for(int i = 1; i <= 6; i++) {
                int next = cur + i, nx = 0, ny = 0;
                if(next > n * n) break;
                calCoord(next, n, nx, ny);
                if(board[nx][ny] != -1) next = board[nx][ny];
                if(step.find(next) == step.end()) {
                    step[next] = 1 + step[cur];
                    q.push(next);
                }
            }
            
        }
        
        return -1;
    }
    
    // calculate coordinate
    void calCoord(int id, int n, int& nx, int& ny) {
        nx = (id - 1) / n;
        ny = (id - 1) % n;
        if(nx & 1) ny = n - 1 - ny;
        nx = n - 1 - nx;
    }
};