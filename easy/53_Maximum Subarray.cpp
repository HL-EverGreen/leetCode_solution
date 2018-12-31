class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // array & DP & DC
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 100%
        
        // much like DP, opt[i] = max(opt[i - 1] + A[i], 0)
        int res = INT_MIN, sum = 0;
        for(auto num : nums) {
            sum += num;
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
        
        // DC's time complexity would be O(nlogn)
        // can refer to 6140 assignment 4 problem 3.
    }
};