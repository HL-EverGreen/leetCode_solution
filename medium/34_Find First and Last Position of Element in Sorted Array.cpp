class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) { //binary_search
        int low=0,high=nums.size(),mid,left,right;
        while(low<high){ //find the index of the most left element equals to target, or index of the least element bigger than target
            mid=low+(high-low)/2;
            if(nums[mid]>=target) high=mid;
            else low=mid+1;
        }
        
        left=low;
        low=0,high=nums.size();
        
        while(low<high){ //find (index+1) of the most right element equals to target, or index of the least element bigger than target
            mid=low+(high-low)/2;
            if(nums[mid]<=target) low=mid+1;
            else high=mid;
        }
        right=low;
        //if right==left, means that can't find element equals to target in #nums#
        //if there is only one element equals to target, that would have: right=left+1
        return left==right?vector<int>({-1,-1}):vector<int>({left,right-1});
    }
};