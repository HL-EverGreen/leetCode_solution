class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // binary search
        // time complexity: O(logn), space complexity: O(1)
        // 8ms, beats 97.43%
        
        // Main idea:
        // Before target, equal pair index is (even, odd), and can be converted to each other with (mid^1)
        // After target, equal pair index is (odd, even), and can't use (mid^1)
        // Use nums[mid] == nums[mid ^ 1] to determine whether neighbor pair is equal.
        int n = nums.size() - 1, left = 0, right = n;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == nums[mid ^ 1]) { left = mid + 1; }      // Still in first part
            else { right = mid; }                                   // At target or in second part
        }
        return nums[right];
    }
};