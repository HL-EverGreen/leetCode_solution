class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // array & bitset
        // time complexity: O(n), space complexity: O(n)
        // 12ms, beats 91.64%
        
        // main idea:
        // b[i] = 1 represent there exists combination whose sum == i
        // since we only need to check whether b[sum / 2] is 1, so we only need MAX_NUM * MAX_ARRAY_SIZE / 2 + 1 size
        const int MAX_NUM = 100;
        const int MAX_ARRAY_SIZE = 200;
        int sum = 0;
        bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> b(1);      // we only need the second half
        for(auto num : nums) {
            sum += num;
            b |= (b << num);
        }
        return !(sum % 2) && b[sum / 2];
    }
};