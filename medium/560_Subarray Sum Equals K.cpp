class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // prefix sum
        // time complexity: O(n), space complexity: O(n)
        // 24ms, beats 99%
        
        // Main idea:
        // Record number of each prefix sum.
        // e.g. a[0] + ... + a[10] = m, and a[0] + ... + a[12] = m + k
        // So a[11] + a[12] = k, we find a subarray satistying the requirement
        
        int sum = 0, res = 0;
        unordered_map<int, int> sumNum;
        // Initial condition, there is one subarray sum == 0
        sumNum[0] = 1;
        for(auto num : nums) {
            sum += num;
            res += sumNum[sum - k];
            sumNum[sum]++;
        }
        return res;
        
        
        // Normal sliding window doesn't work since exist negative numbers
        /*
        int start = 0, end = 0, sum = 0, res = 0, n = nums.size();
        for(; end < n; ++end) {
            sum += nums[end];
            while(sum > k) {
                sum -= nums[start++];
            }
            if(sum == k) { ++res; }
        }
        return res;
        */
    }
};