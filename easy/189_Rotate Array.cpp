class Solution {
public:
    void rotate(vector<int>& nums, int k) {  //move_array_k_times
        int num_size=nums.size(), tmp=0, prev=0, replaced_count=0;
        k%=num_size;
        
        for(int start=0;replaced_count<num_size;start++){ //swap element with k steps one time instead of 1 step
            prev=nums[start];
            int next_pos=(start+k)%num_size;
            int stop=next_pos;
            do{
                tmp=nums[next_pos];
                nums[next_pos]=prev;
                prev=tmp;
                next_pos=(next_pos+k)%num_size;
                replaced_count++;
            }while(next_pos!=stop);
        }
        
        //insert operation consumes too much time
        /*
        k=k%nums.size();
        for(int i=0;i<k;i++){
            int tmp=nums.back();
            nums.pop_back();
            nums.insert(nums.begin(),tmp);
        }
        */
    }
};