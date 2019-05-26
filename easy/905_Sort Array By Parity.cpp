class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        // Array
        // time complexity: O(n), space complexity: O(1)
        // 20ms, beats 99.93%
        
        // Main idea:
        // Two pointers, first points to next place can be swapped.
        // The second pointrs to next place should be examined.
        int size = A.size(), fi = 0, se = 0;
        for(; se < size; se++) {
            if((A[se] & 1) == 0) { swap(A[fi++], A[se]); }
        }
        return A;
    }
};