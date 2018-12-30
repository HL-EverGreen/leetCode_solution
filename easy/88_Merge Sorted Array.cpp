class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.35%
        
        // compare from end to start, and add elements from nums2 into nums1
        int index1 = m - 1, index2 = n - 1, target = m + n - 1;
        while(index2 >= 0) {
            nums1[target--] = (index1 >= 0 && nums1[index1] > nums2[index2] ? nums1[index1--] : nums2[index2--]);
        }
    }
};