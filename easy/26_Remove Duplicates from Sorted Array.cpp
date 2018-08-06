class Solution {
public:
    int removeDuplicates(vector<int>& nums) {//two indexs
        int i=0;
        for(auto num:nums){
            if(i<1 || num>nums[i-1]) //only element which differ from(bigger than) the former one could be placed in the array
                nums[i++]=num;
        }
        return i;
    }
};