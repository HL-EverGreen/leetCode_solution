class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        // array & two pointers
        // time complexity: O(n), space complexity: O(1)
        // 84ms, beats 92.03%
        
        // Main idea:
        // Use one pointer to track all odd positions, and another to 
        // track all even positions. And swap between them.
        int size = A.size(), evenIdx = 0, oddIdx = 1;
        for(; oddIdx < A.size(); oddIdx += 2) {
            while((A[oddIdx] & 1) == 0) {
                swap(A[oddIdx], A[evenIdx]);
                evenIdx += 2;
            }
        }
        return A;
    }
};