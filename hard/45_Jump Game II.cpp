class Solution {
public:
    int jump(vector<int>& nums) {
        // array & BFS
        // Time complexity: O(n)
        // each round compute new range which can be reached in one move from the current range
        
        // start and end is the current range in this round
        int n_size = nums.size(), step = 0, start = 0, end = 0;
        while(end < n_size - 1) {
            step++;
            int cur_max_end = end; 
            for(int i = start; i <= end; i++) {
                if(nums[i] + i >= n_size - 1) {
                    return step;
                }
                cur_max_end = max(cur_max_end, nums[i] + i);
            }
            start = end + 1;
            end = cur_max_end;
        }
        // handle case of input nums's size == 0 or == 1
        return step;
    }
};