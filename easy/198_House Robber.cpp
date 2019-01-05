class Solution {
public:
    int rob(vector<int>& nums) {
        // dynamic programming
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // can also be written in style of (recursive - top-down | recursive + memo - top-down | iterative + memo - bottom-up | iterative + two-variable - bottom-up)
        int size = nums.size();
        if(size < 1) { return 0; }
        else if(size == 1) { return nums[0]; }
        
        vector<int> max_profit(size, 0);
        max_profit[0] = nums[0];
        max_profit[1] = max(nums[0], nums[1]);

        for(int i = 2; i < size; i++) {
            max_profit[i] = max(max_profit[i - 1], max_profit[i - 2] + nums[i]);
        }
        return max_profit[size - 1];
    }
};