class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // array & DP
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 97.24%
        
        // Similar to buy and sell stock, second and third element depends on the former.
        int n = nums.size();
        if(n < 3) return false;
        
        int fi = nums[0], se = INT_MAX;
        for(auto num : nums) {
            if(num > se) return true;       // Exist third element > second element, return true
            if(num > fi) se = min(se, num); // Update smaller second element
            fi = min(fi, num);              // Update smaller first element
        }
        return false;
    }
};