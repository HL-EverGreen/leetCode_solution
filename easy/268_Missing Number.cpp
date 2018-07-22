class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> res(nums.size()+1,1);
        for(int i=0;i<nums.size();i++){
            res[nums[i]]--;
        }
        for(int i=0;i<=nums.size();i++){
            if(res[i]==1) return i;
        }
    }
};