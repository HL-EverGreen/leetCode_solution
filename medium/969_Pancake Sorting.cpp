class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        // array
        // time complexity: O(n^2), space complexity: O(1)
        // 8ms, beats 90.29%
        
        // Main idea:
        // Brute force, each loop place the biggest number in the remaining set to its right position (the next most right position)
        int size = A.size();
        vector<int> res;
        
        /* Current biggest number */
        for(int i = size, j; i > 0; i--) {
            /* Find current biggset number's position */
            for(j = 0; A[j] != i; j++);
            /* Swap */
            reverse(A.begin(), A.begin() + j + 1);
            res.push_back(j + 1);
            reverse(A.begin(), A.begin() + i);
            res.push_back(i);
        }
        return res;
    }
};