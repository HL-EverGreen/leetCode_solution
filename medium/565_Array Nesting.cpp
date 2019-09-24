class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 96.33%
        
        // Main idea:
        // Just find largest cycle, after visiting an element,
        // set its value to -1 to avoid visit again.
        
        int res = 0;
        int N = nums.size();
        
        for(int i = 0; i < N; ++i) {
            int len = 0;
            for(int cur = i; nums[cur] >= 0; ++len) {   // Attempt walk along the cycle
                int next = nums[cur];
                nums[cur] = -1;
                cur = next;
            }
            res = max(res, len);
        }
        
        return res;
    }
};