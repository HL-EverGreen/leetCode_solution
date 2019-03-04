class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        // DFS
        // time complexity: O(N!)
        // 4ms, beats 100%
        
        // main idea:
        // For each round in dfs, find all possible pairs (A[i] and A[last]) can be squareful, swap A[i] with A[last + 1], and enter next round
        // When last == size - 1, we reaches at the end, and return 1
        
        int last = -1;
        return helper(A, last);
    }
    
    int helper(vector<int>& A, int last) {
        int size = A.size(), res = 0;
        if(last == size - 1) return 1;
        unordered_set<int> s;                                                                                           // use set to avoid duplicate permutations
        for(int i = last + 1; i < size; i++) {
            if(s.insert(A[i]).second && (last == -1 || pow((int)sqrt(A[last] + A[i]), 2) == A[last] + A[i])) {          // notice should convert to int!
                swap(A[last + 1], A[i]);
                res += helper(A, last + 1);
                swap(A[last + 1], A[i]);
            }
        }
        return res;
    }
};


// DP
// time complexity: O(2^n * n^2)
// space complexity: O(2^n * n)
// 思路见：https://www.acwing.com/solution/leetcode/content/1034/
/*
class Solution {
public:

    bool isSquare(int x) {
        int t = sqrt(x);
        return t * t == x;
    }

    int fact(int x) {
        int t = 1;
        for (int i = 2; i <= x; i++)
            t *= i;
        return t;
    }

    int numSquarefulPerms(vector<int>& A) {
        int n = A.size();

        sort(A.begin(), A.end());

        vector<int> s;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] != A[i - 1]) {
                s.push_back(cnt);
                cnt = 0;
            }
            cnt++;
        }
        s.push_back(cnt);

        vector<vector<int>> f(1 << n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
            f[1 << i][i] = 1;

        for (int S = 1; S < 1 << n; S++)
            for (int i = 0; i < n; i++)
                if (S & (1 << i))
                    for (int j = 0; j < n; j++)
                        if (!(S & (1 << j)) && isSquare(A[i] + A[j])) {
                            f[S | (1 << j)][j] += f[S][i];
                        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += f[(1 << n) - 1][i];

        for (int i = 0; i < s.size(); i++)
            ans /= fact(s[i]);

        return ans;
    }
};
*/