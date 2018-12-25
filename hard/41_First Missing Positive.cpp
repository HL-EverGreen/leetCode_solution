class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // array
        // Time complexity: o(n)
        // 4ms, beats 86.69%
        
        // Put each number in its right place.
        // For example:
        // When we find 5, then swap it with A[4].
        // At last, the first place where its number is not right, return the place + 1.
        
        int n_size = nums.size();
        for(int i = 0; i < n_size; i++) {
            while(nums[i] > 0 && nums[i] <= n_size && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } 
        }
        
        for(int i = 0; i < n_size; i++) {
            if(nums[i] != i + 1) { return i + 1; }
        }
        return n_size + 1;
    }
};