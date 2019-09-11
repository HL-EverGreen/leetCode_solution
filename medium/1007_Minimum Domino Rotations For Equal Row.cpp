class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 116ms, beats 90.88%
        
        // Main idea:
        // The only possible candidates is among A[0] and B[0].
        // We try A[0] first, and track missing count in A and B, return minimal one.
        // Then B[0] in same procedure.
        
        int n = A.size();
        int cand = A[0];
        for(int i = 0, a = 0, b = 0; i < n && (A[i] == cand || B[i] == cand); ++i) {
            if(A[i] != cand) ++a;
            else if(B[i] != cand) ++b;
            if(i == n - 1) return min(a, b);
        }
        
        cand = B[0];
        for(int i = 0, a = 0, b = 0; i < n && (A[i] == cand || B[i] == cand); ++i) {
            if(A[i] != cand) ++a;
            else if(B[i] != cand) ++b;
            if(i == n - 1) return min(a, b);
        }
        return -1;
    }
};