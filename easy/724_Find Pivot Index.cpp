class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 20ms, beats 95.67%
        
        // Main idea:
        // Get total sum first and compare ony by one.
        
        int total = 0;
        int sum = 0;
        int N = nums.size();
        
        total = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < N; ++i) {
            if(2 * sum == total - nums[i]) return i;
            sum += nums[i];
        }
        return -1;
    }
};