class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int g=nums.size();
        for(int i=0;i<g;i++)
            if(nums[i]==0){
                nums.erase(nums.begin()+i,nums.begin()+i+1);
                nums.push_back(0);
                i--;
                g--;
            }
    }
};