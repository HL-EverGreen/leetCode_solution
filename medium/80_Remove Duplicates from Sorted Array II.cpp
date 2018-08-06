class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //a more simple two index method, beats 100%
        int i=0;
        for(auto n:nums){
            if(i<2||n>nums[i-2])
                nums[i++]=n;
        }
        return i;
        
        //traditional two index method, beats 100%(actually the variable i is not necessary, 
        //we can use nums[len]=num instead of swap(nums[len],nums[i]) )
        /*
        int prev,count=0,len=0,i=0;
        for(auto num:nums){
            if(i==0){
                prev=num;
                count=0;
                len++;
                i++;
                continue;
            }
            if(num==prev){
                if(count<1){
                    if(i!=len) swap(nums[i],nums[len]);
                    len++;
                }
                count++;
            }else{
                if(i!=len) swap(nums[i],nums[len]);
                len++;
                prev=num;
                count=0;
            }
            i++;
        }
        return len;
        */
    }
};