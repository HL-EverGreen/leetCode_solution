class Solution {
public:
    void sortColors(vector<int>& nums) {//tracking three positions
        /*
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
            else mid++;
        }
        */
        
        //or we could also count the number of each color
        int r=0, w=0, b=0; // label the end of different colors;
        for(int num: nums){
            if(num==0) {nums[b++]=2; nums[w++]=1; nums[r++]=0; } 
            else if(num==1) {nums[b++]=2; nums[w++]=1;}
            else if(num==2) b++;
        }
        
    }
};