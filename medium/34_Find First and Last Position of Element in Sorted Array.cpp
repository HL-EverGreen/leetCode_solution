class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // array & binary search
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 100%
        
        // two binary search
        // first binary search: find index of first element >= target
        // second binary search: find index of first element > target
        // if index1 = index2, then no target exists in array
        
        int low, high, left = 0, right = nums.size();   // use nums.size() rather than nums.size() - 1 !!! because $right$ may need equal to nums.size()
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target) {
                right = mid;
            } else { left = mid + 1; }
        }
        
        low = left;
        left = 0;
        right = nums.size();
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid;
            } else { left = mid + 1;}
        }
        
        high = left;
        return (low == high ? vector<int>({-1, -1}) : vector<int>({low, high - 1}));
    }
};