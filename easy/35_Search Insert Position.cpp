class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // array & binary search

        // method 1
        // Time complexity: O(logn)
        // 4ms, 98.74%
        // better binary search format can be seen in method 3

        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        // check if target is the biggest one
        if(target > nums.back()) {
            return right + 1;
        }
        else return right;


        // method 2
        // brute force
        // Time complexity: O(n)
        /*
        int i=0;
        for(auto num:nums){
            if(num>=target) //use num instead of nums[i] to save running time,
                            //actually this method has the same running speed as partition
                            //However, when the NUMS has numerous elements, choose partition maybe wiser
                return i;
            i++;
        }
        return i;
        */
        
        
        // method 3, using binary search so simply!!
        //or we can use partition
        /*
        int lb=0,hb=nums.size()-1,mid;
        while(lb<=hb){
            mid=(lb+hb)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                hb=mid-1;
            else
                lb=mid+1;
        }
        return lb;
        */
    }
};