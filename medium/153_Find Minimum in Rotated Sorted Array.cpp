class Solution {
public:
    int findMin(vector<int>& nums) {
        // array & binary search
        // time complexity: O(logn), space complexity: O(1)
        // 0ms, beats 100%
        
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            if(nums[left] < nums[right]) { return nums[left]; }
            
            int mid = left + (right - left) / 2;
            if(nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};