class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 99.53%
        
        // 从后往前找到第一个小于后面元素的元素
        // 将该元素后所有元素反向
        // 从反向后该元素的位置向后找，找到第一个比该元素大的值并将其与该元素交换（若i==0则省略该步骤，即反向后已经是最小排列）
        int i = nums.size() - 1;
        while(i >= 1 && nums[i - 1] >= nums[i]) { i--; }
        for(int j = i, k = nums.size() - 1; j < k;) { swap(nums[j++], nums[k--]); }
        if(i > 0) {
            int j = i--;
            while(nums[j] <= nums[i]) { j++; }
            swap(nums[j], nums[i]);
        }


        // More understandable version
        // Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
        // Find the largest index l > k such that nums[k] < nums[l].
        // Swap nums[k] and nums[l].
        // Reverse the sub-array nums[k + 1:].

        int N = nums.size(), k = -1, l;
        for(int i = N - 2; i >= 0; --i) {
            if(nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        if(k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(l = N - 1; l > k; --l) {
            if(nums[l] > nums[k]) {
                swap(nums[l], nums[k]);
                reverse(nums.begin() + k + 1, nums.end());
                return;
            }
        }
    }
};