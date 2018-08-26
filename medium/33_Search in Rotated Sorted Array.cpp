class Solution {
public:
    int search(vector<int>& nums, int target) {//binary search
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            
            //if exists duplicate, add following code
            /*
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++; high--; continue;
            }
            */
            
            if(nums[mid]>=nums[low]){ //左边有序，则对左边进行判断
                if(nums[mid]>target && target>=nums[low]) high=mid-1;
                else low=mid+1;
            }else{ //右边有序，对右边进行判断
                if(nums[mid]<target && target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
};