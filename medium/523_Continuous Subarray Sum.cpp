class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // array & prefix
        // time complexity: O(n), space complexity: O(n)
        // 28ms, beats 82.36%
        
        // Main idea:
        // Similar to prefix sum, keep current mod.
        // If current mod has occured, see if length is >= 2
        
        unordered_map<int, int> m;
        m[0] = -1;  // Initialization, important!!!
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if(k != 0) sum %= k;
            if(m.count(sum)) {
                if(i - m[sum] > 1) return true;
            } else m[sum] = i;  // Keep current mod
        }
        return false;
    }
};