class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 16ms, beats 97.25%
        
        // method 1
        // use hash table to record value and its index
        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); i++) {
            if(count.find(nums[i]) != count.end() && i - count[nums[i]] <= k) { return true; }
            count[nums[i]] = i;
        }
        return false;
        
        
        // method 2
        // use set and update set continually
        /*
        if(k <= 0) { return false; }
        int n_size = nums.size();
        if(k >= n_size) { k = n_size-1; }
        unordered_set<int> mySet;
        
        for(int i = 0; i < n_size; i++) {
            if(i > k) { mySet.erase(nums[i - k - 1]); }
            if(mySet.find(nums[i]) != mySet.end()) { return true; }
            mySet.insert(nums[i]);
        }
        return false;
        */
    }
};