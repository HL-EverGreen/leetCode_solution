class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.26%
        
        // since all elements are integer (no fragmentation), so we can calculate products from two directions, be sure to eliminate influence of 0
        int front_product = 1, back_product = 1, n_size = nums.size(), res = INT_MIN;
        
        for(int i = 0; i < n_size; i++) {
            front_product *= nums[i];
            back_product *= nums[n_size - i - 1];
            res = max(res, max(front_product, back_product));
            front_product = (front_product == 0 ? 1 : front_product);
            back_product = (back_product == 0 ? 1 : back_product);
        }
        return res;
    }
};