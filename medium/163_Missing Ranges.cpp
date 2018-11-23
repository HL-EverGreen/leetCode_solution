class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        // INT boundary consideration
        // time complexity: O(n)
        
        nums.insert(nums.begin(), lower);
        nums.push_back(upper);
        int n = nums.size();
        vector<string> res;
        for (int i = 1; i < n; i++) {
            long  dis = (long)nums[i] - (long)nums[i - 1] + (i == 1 ? 1 : 0) + (i == n - 1 ? 1 : 0);
            if (dis == 2)
                res.push_back(to_string(nums[i] - (i == n - 1 ? 0 : 1)));
            else if (dis > 2)
                res.push_back(to_string(nums[i - 1] + (i == 1 ? 0 : 1)) + "->" + to_string(nums[i] - (i == n - 1 ? 0 : 1)));
        }
        return res;
    }
};