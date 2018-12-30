class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 89.79%
        
        // XOR each elements and i from 0 to nums.size()
        // so the res would be the missing number

        int i = 0, res = nums.size(); // notice the initial of res would be nums.size() !!
        for(auto num : nums) {
            res ^= num;
            res ^= i++;
        }
        return res;
    }
};