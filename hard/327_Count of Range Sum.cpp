class Solution {
public:
    typedef vector<long>::iterator iter;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        // merge sort & array pair pattern
        // time complexity: O(nlogn), space complexity: O(n) + stack memory
        // 28ms, beats 83.02%
        
        // Similar to LC 315 and LC 493
        // Transform the input to ‘sum’ representing total sum of all elements up to now.
        // So the question becomes given an array, find number of pair (sum[i], sum[j]) that lower <= sum[j] - sum[i] <= upper while i < j
        // So we can use merge sort. 
        // But the difference is the former only find pair satisfy 单边关系，而这题要找双边关系(差值在一定范围内)
        // So do twice 单边关系
        
        int N = nums.size();
        int res = 0;
        vector<long> sum(N + 1, 0);
        for(int i = 1; i <= N; ++i) sum[i] = sum[i - 1] + nums[i - 1];  // Calculate sum array
        
        mergeCount(sum.begin(), sum.end(), res, lower, upper);
        return res;
    }
    
    /* Calculate the result and merge two sorted subarrays */
    void mergeCount(iter start, iter end, int& res, int lower, int upper) {
        if(end - start <= 1) return;
        iter mid = start + (end - start) / 2;
        mergeCount(start, mid, res, lower, upper);
        mergeCount(mid, end, res, lower, upper);
        for(iter m = mid, n = mid, i = start; i < mid; ++i) {
            while(m < end && *m - *i < lower) ++m;
            while(n < end && *n - *i <= upper) ++n;
            res += n - m;   // Add number of sum[j] which satisfying the requirement
        }
        inplace_merge(start, mid, end);
    }
};