class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 98.98%
        
        // slide window
        int size = nums.size(), front = 0, back = 0, sum = 0, res = size + 1;
        
        for(; back < size; back++) {
            sum += nums[back];
            while(sum >= s) {
                res = min(res, back - front + 1);
                sum -= nums[front++];
            }
        }
        return res > size ? 0 : res;
    }
};