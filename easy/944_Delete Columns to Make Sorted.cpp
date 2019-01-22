class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        // array
        // time complexity: O(nk), k is the A[0].length(), space complexity: O(1)
        // 44ms, beats 97.43%
        
        int res = 0;
        for(int c = 0; c < A[0].size(); c++) {
            for(int i = 1; i < A.size(); i++) {
                if(A[i][c] < A[i - 1][c]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};