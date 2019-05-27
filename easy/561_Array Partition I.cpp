class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // array
        // time complexity:O(n), space complexity: O(20001)
        // 60ms, beats 96.17%
        
        // Main idea:
        // Just pair adjacent two numbers in order
        int size = nums.size(), res = 0;
        bool flg = true;                    // denote whether it's the smaller one in the pair
        vector<int> record(20001, 0);
        
        for(auto num : nums) {
            record[num + 10000]++;
        }
        
        for(int i = 0; i < 20001;) {
            if(record[i] > 0) {
                if(flg) {                   // Smaller number in a pair
                    res += (i - 10000);
                    record[i]--;
                    flg = false;
                } else {                    // Larger number in a pair
                    record[i]--;
                    flg = true;
                }
            } else { i++; }
        }
        return res;
    }
};