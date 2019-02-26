class Solution {
public:
    int countTriplets(vector<int>& A) {
        // DFS->memo DFS->DP
        // same as LC.494 Target Sum

        // method 1:
        // DP
        // time complexity: O(2^16 * n)
        // time limit exceeded..
        
        int n = A.size();
        vector<vector<int>> f(3, vector<int>(1 << 16, 0));
        for(int i = 0; i < n; i++) f[0][A[i]]++;
        for(int i = 1; i < 3; i++) {
            for(int j = 0; j < (1 << 16); j++) {
                for(int k = 0; k < n; k++)
                    f[i][j & A[k]] += f[i - 1][j];
            }
        }
        return f[2][0];

        // method 2:
        // dfs with memorization
        // 140ms, beats 84.55%
        // O(n^2) ? worse: O(n^3)
        /*
        int n = A.size(), ans = 0;
        vector<int> f(1 << 16, -1);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int x = A[i] & A[j];
                if (f[x] == -1) {
                    f[x] = 0;
                    for (int k = 0; k < n; k++)
                        if ((x & A[k]) == 0)
                            f[x]++;
                }
                ans += f[x];
            }

        return ans;
        */
    }
};