class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // array & dp
        // time complexity: O(n), space complexity: O(1) -> O(10000)
        // 8ms, beats 100%
        
        // main idea:
        // If we sort all the numbers into buckets indexed by these numbers, 
        // this is essentially asking you to repetitively take an bucket while giving up the 2 buckets next to it. (the range of these numbers is [1, 10000])
        
        // skip_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you skip the ith bucket.
        // take_i : the best result for sub-problem of first (i+1) buckets from 0 to i, while you take the ith bucket.
        
        // DP formula:
        // take[i] = skip[i-1] + values[i];
        // skip[i] = Math.max(skip[i-1], take[i-1]);
        
        int n = 10001, take = 0, skip = 0;
        vector<int> values(n, 0);
        for(auto& num : nums) values[num] += num;
        for(int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};