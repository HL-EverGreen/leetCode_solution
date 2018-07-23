class Solution {
public:
    int singleNumber(vector<int>& nums) {//bit operation, a general solution for this kind of question is shown in discuss area
        int ones = 0, twos = 0;
        for(int i = 0; i < nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};