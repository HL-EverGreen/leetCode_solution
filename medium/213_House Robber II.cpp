class Solution {
public:
    int rob(vector<int>& nums) {
        // dynamic programming
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 100%
        
        // this problem can be divided into two subproblems (House Robber I), with index from 0 to size - 2 and 1 to size - 1 respectively
        // then return the max value of two DP
        int size = nums.size();
        if(size < 2) { return size ? nums[0] : 0; }
        return max(rob(nums, 0, size - 2), rob(nums, 1, size - 1));
    }
    
    // bottom up with two variables
    int rob(vector<int>& nums, int start, int end) {
        int prev = 0, cur = 0, res = 0;
        for(int i = start; i <= end; i++) {
            res = max(prev + nums[i], cur);
            prev = cur;
            cur = res;
        }
        return res;
    }
};