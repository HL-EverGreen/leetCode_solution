class Solution {
public:
    int search(vector<int>& nums, int target) {
        // binary search
        // time complexity: O(logn), space complexity: O(1)
        // 52ms, beats 87.15%
        
        // Use left <= right because we have to check every number
        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) { return mid; }
            else if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};