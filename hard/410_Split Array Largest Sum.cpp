class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // split array & greedy & binary search
        // time complexity: O(nlogn), space complexity: O(1)
        // 4ms, beats 100%
        
        // main idea:
        // 1. Divide into two subproblems:
        //    1) binary search if doable(nums, cuts, max) is true in range of (left, right)
        //       where left is the max number of all nums, right is their sum
        //    2) doable(nums, cuts, max): use greedy algorithm to check if using number of cuts cut, can divide nums into cuts + 1 groups and each group's sum <= max
        
        long left = 0, right = 0;
        for(auto num : nums) {
            left = max(left, (long)num);
            right += num;
        }
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(doable(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    // greedy
    bool doable(const vector<int>& nums, int cuts, long max) {
        long acc = 0;
        for(auto num : nums) {
            if(num > max) return false;                  
            else if(acc + num <= max) acc += num;        // take this num into acc and do not cut here
            else {
                if(cuts-- <= 0) return false;
                acc = num;
            }
        }
        return true;
    }
};