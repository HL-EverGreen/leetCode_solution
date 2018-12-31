class Solution {
public:
    int trap(vector<int>& height) {
        // array & two pointers
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 100%
        
        // keep the higher one among height[left] and height[right]
        // then compare the lower one with its corresponding max_height and decrease the range
        
        int left = 0, right = height.size() - 1, res = 0, left_max = 0, right_max = 0;
        
        while(left < right) {
            if(height[left] >= height[right]) {
                if(height[right] > right_max) {
                    right_max = height[right];
                } else {
                    res += (right_max - height[right]);
                }
                right--;
            } else {
                if(height[left] > left_max) {
                    left_max = height[left];
                } else {
                    res += (left_max - height[left]);
                }
                left++;
            }
        }
        
        return res;
    }
};