class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 99.21%
        
        // Main idea:
        // Use unordered_set::erase to determine whether 
        // there is a value and erase it if there is.
        
        unordered_set<int> seen(nums1.begin(), nums1.end());
        vector<int> res;
        
        for(const auto& n : nums2) {
            if(seen.erase(n)) res.emplace_back(n);
        }
        return res;
    }
};