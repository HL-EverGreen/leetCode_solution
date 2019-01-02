class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // array
        // Tortoise and the hare algorithm OR binary search
        
        // method 1
        // Tortoise and the hare algorithm (to calculate the start point of the loop)
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 84.96%
        
        int fast = 0, slow = 0;
        while(true) {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow) { break; }
        }
        
        fast = 0;
        while(true) {
            fast = nums[fast];
            slow = nums[slow];
            if(fast == slow) { return fast; }
        }
        
        
        // method 2
        // binary search
        // time complexity: O(nlogn), space complexity: O(1)
        // 12ms, beats 41.72%
        /*
        int n_size = nums.size() - 1, low = 0, high = n_size;
        
        while(low < high) {
            int mid = low + (high - low) / 2, count = 0;
            for(auto num : nums) {
                if(num <= mid) { count++; }
            }
            if(count > mid) { 
                high = mid;                     // duplicate number is <= mid
            } else {
                low = mid + 1;                  // duplicate number is > mid
            }
        }
        return low;
        */
    }
};