class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // array
        // time complexity: 0(n), space complexity: O(1)
        // 16ms, beats 63.6%
        
        // +k step replace until replace count >= size
        int size = nums.size(), count = 0;
        k %= size;
        
        for(int i = 0; i < k && count < size; i++) {
            int start = i, temp = nums[start];
            while((start + size - k) % size != i) {
                nums[start] = nums[(start + size - k) % size];
                start = (start + size - k) % size;
                count++;
            }
            nums[start] = temp;
            count++;
        }
    }
};