class Solution {
public:
    int fixedPoint(vector<int>& A) {
        // binary search
        // time complexity: O(logn), space complexity: O(1)
        // 12ms, beats 97.06%
        
        // Main idea:
        // If A[mid] == mid, search left.
        // If A[mid] > mid, only left part could have chance to have res (all elem distinct and in order)
        // If A[mid] < mid, only right part have chance
        int lo = 0, hi = A.size();
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(A[mid] < mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return A[hi] == hi ? hi : -1;
    }
};