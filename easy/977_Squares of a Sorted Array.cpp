class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // array & two pointers
        // time complexity: O(n), space complexity: O(n)
        // 96ms, beats 98.13%
        
        // Main idea:
        // Continually compare first pointer and second pointer,
        // and compute result from back to start.
        
        int left = 0, right = A.size() - 1, idx = A.size() - 1;
        vector<int> res(A.size());
        
        while(left <= right) {
            if(abs(A[left]) > abs(A[right])) {
                res[idx--] = A[left] * A[left];
                left++;
            } else {
                res[idx--] = A[right] * A[right];
                right--;
            }
        }
        return res;
    }
};