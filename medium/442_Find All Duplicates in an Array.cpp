class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 116ms, beats 83.96%
        
        // Main idea:
        // Put each number in its corresponding position. e.g. put 5 in pos 4.
        // If a number exists twice, then one of them must be out of position.
        vector<int> res;
        int n = nums.size();
        
        /* Put number in corresponding position */
        for(int i = 0; i < n; i++) {
            while(nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        
        /* Find out of position number */
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                res.push_back(nums[i]);
            }
        }
        
        return res;
    }
};