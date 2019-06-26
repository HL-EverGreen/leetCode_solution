class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    int shortestBridge(vector<vector<int>>& A) {
        // BFS
        // time complexity: O(n^3), space complexity: O(1)
        // 36ms, beats 95.92%

        // Main idea:
        // Paint one of the islant into 2 at first to distinguish two islands.
        // Expand the boarder of one island by one block each round.
        // If connect with another island, return shortest path.

        int N = A.size();

        /* Paint one island */
        for(int i = 0, flg = 0; !flg && i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(A[i][j] == 1) {
                    paint(A, i, j);
                    flg = 1;
                    break;
                }
            }
        }
        
        /* Expand one block at each round */
        for(int cur = 2; cur < 2 * N; cur++) {      // Expand with 2 at first
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(A[i][j] == cur) {
                        if(expand(A, cur + 1, i + 1, j) || expand(A, cur + 1, i - 1, j)
                           || expand(A, cur + 1, i, j + 1) || expand(A, cur + 1, i, j - 1)) {
                            return cur - 2;
                        }
                    }
                }
            }
        }
        return -1;
        
    }
    
    // Paint one island (originally 1) into 2
    void paint(vector<vector<int>>& A, int r, int c) {
        if(r < 0 || c < 0 || r >= A.size() || c >= A.size() || A[r][c] != 1) { return; }
        A[r][c] = 2;
        for(int i = 0; i < 4; i++) {
            paint(A, r + dir[i], c + dir[i + 1]);
        }
    }
    
    // Expand nearby blocks of the given one
    bool expand(vector<vector<int>>& A, int cur, int r, int c) {
        if(r < 0 || c < 0 || r >= A.size() || c >= A.size()) { return false; }
        if(A[r][c] == 0) { A[r][c] = cur; }
        return A[r][c] == 1;
    }
};
