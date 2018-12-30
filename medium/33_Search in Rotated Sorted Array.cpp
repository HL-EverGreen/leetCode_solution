class Solution {
public:
    int search(vector<int>& nums, int target) {
        // array & binary search
        // time complexity: O(logn), space complexity: O(1)
        // 4ms, beats 98.98%
        
        int left = 0, right = nums.size() - 1;
        
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[left] <= nums[mid]) {                    // left part is in order, so determine based on left part
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else { left = mid + 1; }
            } else {                                                // right part is in order, so determine based on right part
                if(nums[mid] < target && target <= nums[right]) {   
                    left = mid + 1;
                } else { right = mid - 1; }
            }
        }
        return -1;
    }
};