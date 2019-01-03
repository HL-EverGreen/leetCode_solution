class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // array
        // time complexity: O(log(min(m, n))), time complexity: O(1)
        // 48ms, beats 52.03%
        
        // explaination can be seen here: https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2471/Very-concise-O(log(min(MN)))-iterative-solution-with-detailed-explanation
        int N1 = nums1.size(), N2 = nums2.size();
        if(N1 < N2)  { return findMedianSortedArrays(nums2, nums1); }       // Make sure A2 is the shorter one.
        
        int low = 0, high = 2 * N2;
        while(low <= high) {
            int mid2 = low + (high - low) / 2;                              // Try Cut 2 
            int mid1 = N1 + N2 - mid2;                                      // Calculate Cut 1 accordingly
            
            double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1 - 1) / 2];
            double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[mid1 / 2];
            double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[mid2 / 2];
            
            if(L1 > R2) {                                                   // A1's lower half is too big; need to move C1 left (C2 right)
                low = mid2 + 1;
            } else if(L2 > R1) {                                            // A2's lower half too big; need to move C2 left.
                high = mid2 - 1;
            } else {                                                        // Otherwise, that's the right cut.
                return (max(L1, L2) + min(R1, R2)) / 2;
            }
        }
        return -1;
    }
};