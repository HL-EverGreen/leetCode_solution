class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // window using set
        // time complexity: O(nlogn) ?
        // insert elem into the set first and do lower_bound to let cur point to that elem
        // use prev and next to point the the previous and the next element
        
        // new knowledge: begin() is the pointer which points to the first element, different from end(), which is kind of NULL pointer

        if(k < 0 || t < 0) { return false; }
        
        set<int> window;
        set<int>::iterator prev, cur, next;
        
        for(int i = 0; i < nums.size(); i++) {
            if(window.find(nums[i]) != window.end()) { return true; }
            
            // let cur points to the inserted element
            window.insert(nums[i]);
            prev = cur = next = window.lower_bound(nums[i]);
            
            prev--; next++;
            if(cur != window.begin() && (long) nums[i] - *prev <= t) { return true; }
            if(next != window.end() && *next - (long) nums[i] <= t) { return true; }
            
            // maintain the window length to k
            if(i >= k) { window.erase(nums[i - k]); }
        }
        return false;
    }
};