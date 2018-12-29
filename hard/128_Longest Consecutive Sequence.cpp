class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // array & hash table
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 100%
        
        // method 1:
        // using unordered_map, and mp[num] store its length longest consecuive array containing itself
        unordered_map<int, int> mp;
        int res = 0;
        for(auto num : nums) {
            if(mp[num]) { continue; }
            res = max(res, mp[num] = mp[num + mp[num + 1]] = mp[num - mp[num - 1]] = mp[num + 1] + mp[num - 1] + 1);
        }
        return res;
        
        // method 2:
        // delete consecutive numbers in hash table in each round
        // unordered_set<int> number(nums.begin(), nums.end());
        // int prev, next, res = 0;
        // for(auto num : nums) {
        //     if(number.find(num) != number.end()) {
        //         prev = num - 1; next = num + 1;
        //         while(number.find(prev) != number.end()) { number.erase(prev--); }  // unordered_set erase time complexity: average O(1), worst O(n)
        //         while(number.find(next) != number.end()) { number.erase(next++); }
        //         res = max(res, next - prev - 1);
        //     }
        // }
        // return res;
    }
};