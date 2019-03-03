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