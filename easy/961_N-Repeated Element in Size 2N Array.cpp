class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        // Array
        // time complexity: O(n), space complexity: O(1)
        // 36ms, beats 97.04%
        
        // Main idea:
        // Compare three elements in one time
        int size = A.size();
        for(int i = 2; i < size; i++) {
            if(A[i] == A[i - 2] || A[i] == A[i - 1]) {
                return A[i];
            }
        }
        
        /* Edge case: [2, 1, 3, 2]. Simply return the last one. */
        return A[size - 1];
        
        
        // Method 2:
        // Use random, time complexity: O(4)
        // Main idea:
        // pick two numbers randomly, there is a 25% chance you bump into the repeated number.
        /*
        int i, j;
        while (A[i = rand() % A.size()] != A[j = rand() % A.size()] || i == j);
        return A[i];
        */
    }
};