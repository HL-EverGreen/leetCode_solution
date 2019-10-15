class Solution {
public:
    int longestMountain(vector<int>& A) {
        // array
        
        // two pass
        // time complexity: O(n), space complexity: O(n)
        // 20ms, beats 91.22%
        
        // Main idea:
        // First pass from left to right to count number of continuous ups.
        // Second pass from right to left to count number of continuous downs and update result.
        
        int N = A.size();
        int res = 0;
        int rightCnt = 0;
        vector<int> left(N, 0);
        
        // Left to right, get number of continuous ups
        for(int i = 1; i < N; ++i) {
            if(A[i] > A[i - 1]) left[i] = left[i - 1] + 1;
        }
        
        // Right to left, get number of continuous downs and result
        for(int i = N - 2; i >= 0; --i) {
            if(A[i] > A[i + 1]) ++rightCnt;
            else rightCnt = 0;
            if(left[i] == 0 || rightCnt == 0) continue; // A mountain should has both ups and downs
            res = max(res, left[i] + rightCnt + 1);
        }
        return res;
        
        
        // Follow up: Use O(1) space
        // one pass
        // time complexity: O(n), space complexity: O(1)
        // 20ms, beats 91.22%
        int res = 0, up = 0, down = 0, N = A.size();
        for(int i = 1; i < N; ++i) {
            if((down && A[i - 1] < A[i]) || A[i - 1] == A[i]) up = down = 0;    // Keep pervious up when start to down
            if(A[i - 1] < A[i]) ++up;
            if(A[i - 1] > A[i]) ++down;
            if(up && down) res = max(res, up + down + 1);
        }
        return res;
    }
};