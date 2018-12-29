class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	// array
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 98.88%
        
        // method 1
        // two pointers
        int start = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[start++] = nums[i];
            }
        }
        return start;

        // method 2
        // using erase
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==val){
        //         nums.erase(nums.begin()+i,nums.begin()+i+1);
        //         i--;
        //     }
        // }
        // return nums.size();
    }
};