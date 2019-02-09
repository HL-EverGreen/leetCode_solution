class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // array & sliding window
        // time complexity: O(n), space complexity: O(k)
        // 64ms, beats 100%
        
        // Each round: 
        // Remove element that out of range
        // Remove element that does not need to be considered
        // Add new element
        deque<int> window;
        vector<int> res;
        int nSize = nums.size();
        for(int i = 0; i < nSize; i++) {
            if(!window.empty() && window.front() <= i - k) window.pop_front();              // remove element out of current window
            while(!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();     // delete element which need not to be considered
            window.push_back(i);
            if(i + 1 >= k) res.push_back(nums[window.front()]);                             // start push result at the position of the first window
        }
        return res;
    }
};