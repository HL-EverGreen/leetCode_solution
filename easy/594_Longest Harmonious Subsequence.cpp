class Solution {
public:
    int findLHS(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 88ms, beats 85.43%
        
        // Main idea:
        // Two pass, one for freq count and one for calculating result.
        unordered_map<int, int> m;
        for(auto& num : nums) m[num]++;
        
        int res = 0;
        for(auto& it : m) {
            if(m.count(it.first - 1)) res = max(res, it.second + m[it.first - 1]);
        }
        return res;
    }
};