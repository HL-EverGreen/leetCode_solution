class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 36ms, beats 95.33%
        
        // main idea:
        // First pass: Detect abnormal pair, and keep found min num and max num
        // Second pass: find first number > min_num and last number < max_num, res is the gap length
        
        int size = nums.size(), mi = INT_MAX, ma = INT_MIN, start = -1, end = -1;
        for(int i = 0; i < size - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                mi = min(mi, nums[i + 1]);
                ma = max(ma, nums[i]);
            }
        }
        for(int i = 0; i < size; i++) {
            if(nums[i] > mi && start == -1) start = i;      // find first > mi element
            if(nums[i] < ma) end = i;                       // find last < ma element
        }
        if(start == end) return 0;                          // already sorted
        return end - start + 1;
    }
};