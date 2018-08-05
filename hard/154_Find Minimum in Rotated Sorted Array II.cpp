class Solution {
public:
    int findMin(vector<int>& nums) {  //binary search
        if(nums.size()==1) return nums[0];
        int left=0,right=nums.size()-1;
        while(left<right){
            if(nums[left]<nums[right])
                return nums[left];
            int mid=(left+right)/2;
            if(nums[mid]>nums[right])
                left=mid+1;
            else if(nums[mid]<nums[right]) right=mid;
            else right--;  //We can't determine whether to move right or left when nums[mid]==nums[right], so just let upper bound reduce one
        }
        return nums[left];
    }
};