class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 112ms, beats 92.49%
        
        // Main idea:
        // Take K itself as a carry!
        int N = A.size();
        for(int i = N - 1; i >= 0 && K > 0; i--) {
            A[i] += K;
            K = A[i] / 10;
            A[i] %= 10;
        }
        
        /* If still K, insert new element front of array */
        while(K > 0) {
            A.insert(A.begin(), K % 10);
            K /= 10;
        }
        
        return A;
    }
};