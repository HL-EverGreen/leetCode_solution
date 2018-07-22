class Solution {
public:
    int findDuplicate(vector<int>& nums) {//Tortoise and the hare algorithm, to calculate the start point of the loop
        int slow=0;
        int fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast) break;
        }
        fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[fast];
            if(slow==fast) return slow;
        }
    }
};