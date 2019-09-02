// design & array
// time complexity: reset(): O(1), shuffle(): O(n)
// 192ms, beats 96.68%

// Main idea:
// For shuffle, for each index, just random an index to swap with

class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = nums;
        int n = res.size();
        for(int i = 0; i < n; ++i)  swap(res[i], res[rand() % n]);
        return res;
    }
private:
    vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */