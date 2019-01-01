class Solution {
public:
    void sortColors(vector<int>& nums) {
        // array
        // time complexity: O(n) in one-pass, space complexity: O(1)
        // 0ms, beats 100%
        
        // method 1
        // use three color index from front, label the end of different colors
        int index0 = 0, index1 = 0, index2 = 0;
        for(auto num : nums) {
            if(num == 0) {
                nums[index2++] = 2;
                nums[index1++] = 1;
                nums[index0++] = 0;
            } else if(num == 1) {
                nums[index2++] = 2;
                nums[index1++] = 1;
            } else {
                index2++;               // equals to nums[index2++] = 2;
            }
        }
        
        
        // method 2
        // three pointers, two from front and one from back
        // nums[i] which i < low is all 0, nums[i] which i > high is all 2
        /*
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while(mid <= high) {
            if(nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if(nums[mid] == 2) {
                swap(nums[mid], nums[high--]);
            } else {
                mid++;
            }
        }
        */
        
    }
};