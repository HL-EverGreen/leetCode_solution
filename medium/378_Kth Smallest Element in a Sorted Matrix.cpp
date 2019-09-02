class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // matrix & binary search
        // time complexity: O(nlogn), space complexity: O(1)
        // 36ms, beats 93.71%
        
        // Main idea:
        // Use binary search to determine current check number,
        // and iterate from rightmost element, to count the number of elements less than it
        
        // How does this binary search ensure that the returned result does exist in the matrix?
        // Because when we count number <= target, so 
        //   1) When lo = target - 1 and hi = target, mid = target - 1, so cnt = k - 1, lo = mid + 1 = target
        //   2) When lo = target and hi = target + 1, mid = target, so cnt = k, hi = mid = target
        // In any of the case, the binary search will eventually ends at kth smallest element in the matrix
        
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0, col = n - 1;
            
            // Count number <= mid
            for(int row = 0; row < n; ++row) {
                while(col >= 0 && matrix[row][col] > mid) --col;
                cnt += col + 1;
            }
            
            // Can't directly return, since current mid may not appear in the matrix
            // if(cnt == k - 1) return mid;
            if(cnt > k - 1) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
