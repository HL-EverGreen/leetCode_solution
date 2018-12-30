class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 32ms, beats 99.25%
        
        // main idea: 
        // First traverse: do product from left to right
        // Second traverse: do product from right to left
        int begin_prod = 1, back_prod = 1;
        vector<int> res(nums.size(), 1);
        
        for(int i = 0; i < nums.size(); i++) {
            res[i] *= begin_prod;
            begin_prod *= nums[i];
        }
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= back_prod;
            back_prod *= nums[i];
        }
        
        return res;
    }
};