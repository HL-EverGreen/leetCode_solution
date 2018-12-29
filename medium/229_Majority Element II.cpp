class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 12ms, beats 47.03%
        
        // at most two elements would exist in the result, so we only use num1,num2,count1,count2
        // determine which two numbers appear more (or equal) time than others in first traverse
        // count these two numbers frequency at second traverse
        int num1, num2, count1 = 0, count2 = 0;
        vector<int> res;
        if(nums.size() <2) { return nums; }
        
        num1 = nums[0]; num2 = nums[1];
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == num1) { 
                count1++; 
            } else if(nums[i] == num2) {
                count2++;
            } else if(count1 == 0) {
                num1 = nums[i];
                count1++;
            } else if(count2 == 0) {
                num2 = nums[i];
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        
        // count number of two elements
        count1 = count2 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == num1) { 
                count1++; 
            } else if(nums[i] == num2) {
                count2++;
            }
        }
        
        if(count1 > nums.size() / 3) { res.push_back(num1); }
        if(count2 > nums.size() / 3) { res.push_back(num2); }
        
        return res;
    }
};