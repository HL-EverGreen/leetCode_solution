class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // array
        // 8ms, beats 100%
        
        // compare new element to the n-2 element in the current array
        int cur_len = 0;
        for(auto num:nums) {
            if(cur_len < 2 || num > nums[cur_len - 2]) {
                nums[cur_len++] = num;
            }
        }
        return cur_len;
        
        
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