class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        // binary search
        // time complexity: O(logn), space complexity: O(1)
        // 16ms, beats 79.09%
        
        int lo = 0, hi = A.size() - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(A[mid] < A[mid + 1]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};