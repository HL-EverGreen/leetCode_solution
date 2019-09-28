class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // array & math
        // time complexity: O(n^2), space complexity: O(1)
        // 12ms, beats 93.48%
        
        // Main idea:
        // Sort first, and if smaller two's sum is larger then the big one, then these three edges can consist a triangle
        // First select the largest element, and check smaller two, if can't, increase the smaller one. If can, decrease the bigger one.
        
        sort(nums.begin(), nums.end());
        int res = 0;
        int N = nums.size();
        for(int i = N - 1; i >= 2; --i) {   // Choose the biggest element
            int j = 0, k = i - 1;           // Smaller two
            while(j < k) {
                if(nums[j] + nums[k] > nums[i]) { // nums[j], nums[j + 1],...,nums[k - 1] and nums[k] and nums[i] can consist a triangle.
                    res += k - j;                 // So add k - j.
                    --k;
                } else ++j;
            }
        }
        return res;
    }
};