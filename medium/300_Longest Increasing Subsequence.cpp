class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // method 1
        // time complexity: O(nlogn), space complexity: O(n)
        // 4ms, beats 81.83%
        // Using an timely updating sequence, when a smaller number come up, replace the corresponding old bigger number with it
        
        vector<int> res;
        for(auto num : nums) {
            auto it = lower_bound(res.begin(), res.end(), num);         // lower_bound: find the least element >= specified element, O(logn) - use binary search to find
                                                                        // upper_bound: find the least element > specified element, O(logn) - use binary search to find
            if(it == res.end()) { res.push_back(num); }
            else { *it = num; }
        }
        return res.size();
        
        
        // method 2
        // dynamic programming
        // time complexity: O(n^2), space complexity: O(n)
        
        // Using DP, the essensial of dp is to find the meaning of dp[i]
        // Here, the dp[i] represents the length of the longest increasing sequence which ends with nums[i]
        // So that when nums[j]>nums[i],dp[j]=max(dp[j],dp[i]+1)
        /*
        int size = nums.size(), res = 1;
        if(size < 1) { return 0; }
        vector<int> max_len(size, 1);
        for(int i = 1; i < size; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    max_len[i] = max(max_len[i], max_len[j] + 1);
                }
                res = max(res, max_len[i]);
            }
        }
        return res;
        */
    }
};