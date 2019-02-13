class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 
        
        // main idea:
        // First pass, if encounter an number denoted as a, flip the number to less than 0 whose index == a - 1
        // Second pass, check those number which > 0, and record result
        int size = nums.size();
        vector<int> res;
        for(int i = 0; i < size; i++) {
            int tmp = abs(nums[i]) - 1;                             // to change to index (start from 0)
            nums[tmp] = (nums[tmp] > 0 ? -nums[tmp] : nums[tmp]);
        }
        
        for(int i = 0; i < size; i++) {
            if(nums[i] > 0) res.push_back(i + 1);
        }
        return res;
    }
};