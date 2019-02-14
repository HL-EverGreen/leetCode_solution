class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        // matrix & BFS & bit
        // 32ms, beats 100%
        
        // key point: only allow to revisit same point when key status got updated
        // we use bit representation to present key status (111111 means get all keys)

        if(grid.empty() || grid[0].empty()) return -1;
        int m = grid.size(), n = grid[0].size();
        int dir[5] = {1, 0, -1, 0, 1}, path = 0, K = 0;
        // at most 6 keys, using bitmap 111111
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(64, false)));
        // <postion, hold keys mapping>
        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '@') {
                    q.push({i * n + j, 0});
                    visited[i][j][0] = true;
                }
                if(grid[i][j] >= 'A' && grid[i][j] <= 'F') K++;     // total key number
            }
        }
        
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int x = q.front().first / n, y = q.front().first % n, carry = q.front().second;
                q.pop();
                if(carry == (1 << K) - 1) return path;               // if all keys hold, just return 
                for(int j = 0; j < 4; j++) {
                    int nx = x + dir[j], ny = y + dir[j + 1], new_carry = carry;
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') continue;
                    else if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f') new_carry |= (1 << (grid[nx][ny] - 'a'));               // update hold keys
                    else if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F' && !(new_carry & (1 << (grid[nx][ny] - 'A')))) continue;
                    if(!visited[nx][ny][new_carry]) {
                        q.push({nx * n + ny, new_carry});
                        visited[nx][ny][new_carry] = true;
                    }
                }
            }
            path++;
        }
        return -1;
    }
};