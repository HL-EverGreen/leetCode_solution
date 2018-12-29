class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 45.29%
        
        // method 1
        // use start to fill first part of vector to be non-zero
        // then fill the rest to zero
        int start = 0;
        for(auto num:nums) {
            if(num != 0) {
                nums[start++] = num;
            }
        }
        
        for(int i = start; i < nums.size(); i++) { 
            nums[i] = 0;
        }
        
        // method 2
        // kind of bubble sort, but skip all continous 0
        // 16ms, beats 45.29%
        /*
        int start = 0, end = 0;
        while(end < nums.size()) {
            while(nums[end] == 0 && end < nums.size() - 1) { end++; }
            swap(nums[start++], nums[end++]);
        }
        */

        // method 3:
        // use erase and push_back
        /*
        int g=nums.size();
        for(int i=0;i<g;i++)
            if(nums[i]==0){
                nums.erase(nums.begin()+i,nums.begin()+i+1);
                nums.push_back(0);
                i--;
                g--;
            }
        */
    }
};