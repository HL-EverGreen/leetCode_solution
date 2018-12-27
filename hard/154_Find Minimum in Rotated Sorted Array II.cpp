class Solution {
public:
    int findMin(vector<int>& nums) {
        // array & binary search
        // time complexity: O(logn)
        // 4ms, beats 99.04%
        
        // binary search case:
        // case 1: nums[left] < nums[right], nums[left] is the minimal number
        // case 2: nums[mid] < nums[right], search left
        // case 3: nums[mid] > nums[right], search right
        // case 4: nums[mid] == nums[right], can't determine search left or right, so decrease search range (right--)
        int left = 0, right = nums.size() - 1;

        while(left < right) {
            if(nums[left] < nums[right]) {          // case 1
                return nums[left];
            }
            int mid = left + (right - left) / 2;
            
            if(nums[mid] > nums[right]) {           // case 3
                left = mid + 1;
            } else if(nums[mid] < nums[right]) {    // case 2
                right = mid;
            } else { right --; }                    // case 4
        }
        return nums[left];
    }
};