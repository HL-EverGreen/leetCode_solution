class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 100%
        
        // method 1
        // two pointers, use left to denote replacable element (0 or equal with right)
        // use right to check each element
        int left = 0, right = 0;
        while(right < nums.size()) {
            if(nums[right] != 0) swap(nums[left++], nums[right++]);
            else right++;
        }


        // method 2
        // use start to fill first part of vector to be non-zero
        // then fill the rest to zero
        /*
        int start = 0;
        for(auto num:nums) {
            if(num != 0) {
                nums[start++] = num;
            }
        }
        
        for(int i = start; i < nums.size(); i++) { 
            nums[i] = 0;
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