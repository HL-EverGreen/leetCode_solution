class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 99.35%
        
        // kind of two pointers
        // only element which differ from (bigger than) the former one could be placed in the array
        int start = 0;
        for(auto num : nums) {
            if(start < 1 || num > nums[start - 1]) {
                nums[start++] = num;
            }
        }
        return start;
    }
};