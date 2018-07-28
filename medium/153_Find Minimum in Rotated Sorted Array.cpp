class Solution {
public:
    int findMin(vector<int>& nums) {//partition
        if(nums.size()==1)
            return nums[0];
        int low=0,high=nums.size()-1,temp=0;
        while(high>low){
            temp=(low+high)/2;
            if(nums[temp]>nums[temp+1])
                return nums[temp+1];
            if(temp==low)
                break;
            if(nums[temp]>=nums[0]){
                low=temp+1;
            }
            else if(nums[temp]<nums[0]){
                high=temp;
            }
        }
        return nums[0];
    }
    //more concise version
    /*
     int findMin(vector<int> &num) {
        int start=0,end=num.size()-1;
        
        while (start<end) {
            if (num[start]<num[end])
                return num[start];
            
            int mid = (start+end)/2;
            
            if (num[mid]>=num[start]) {
                start = mid+1;
            } else {
                end = mid;
            }
        }
        
        return num[start];
    }
    */
};