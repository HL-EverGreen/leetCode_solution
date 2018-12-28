class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // array & binary search
        // time complexity: 0(logn), space complexity: O(1)
        
        // Binary search case:
        // case 1: nums[mid] == target, return true
        // case 2: nums[left] < nums[mid], then left part is in order so determine next step based on left range
        // case 3: nums[left] > nums[mid], then right part is in order so determine next step based on right range
        // case 4: nums[left] == nums[mid], can't determine which part is in order, so decrease search range (left++)
        int left = 0, right = nums.size() - 1;
        
         while(left <= right) {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target) {
                return true;
            } else if(nums[left] == nums[mid]){
                left++;
            } else if(nums[left] < nums[mid]) {
                if(nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else { left = mid + 1; }
            } else {
                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else { right = mid - 1; }
            }
        }

        return false;
    }
};