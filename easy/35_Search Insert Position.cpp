class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {//partition
        int i=0;
        for(auto num:nums){
            if(num>=target) //use num instead of nums[i] to save running time,
                            //actually this method has the same running speed as partition
                            //However, when the NUMS has numerous elements, choose partition maybe wiser
                return i;
            i++;
        }
        return i;
        
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