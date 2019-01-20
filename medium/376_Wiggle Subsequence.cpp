class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        // array & DP
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // up[i] means length of longest wiggle subsequence ending with ascending
        // down[i] means length of longest wiggle subsequence ending with descending
        int size = nums.size();
        if(size < 2) { return size; }
        vector<int> up(size, 0), down(size, 0);
        up[0] = down[0] = 1;
        
        for(int i = 1; i < size; i++) {
            if(nums[i] > nums[i - 1]) {
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];
            } else if(nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            } else {
                down[i] = down[i - 1];
                up[i] = up[i - 1];
            }
        }
        return max(up[size - 1], down[size - 1]);
    }
};