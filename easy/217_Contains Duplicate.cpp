class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 24ms, beats 80.55%
        
        // method 1
        // set.size() != nums.size() ? true : false
        return nums.size() != unordered_set<int>(nums.begin(), nums.end()).size();
        
        
        // method 2
        // use set
        /*
        unordered_set<int> count;
        for(int num : nums) {
            if(count.find(num) != count.end()) {
                return true;
            }
            count.insert(num);
        }
        return false;
        */
    }
};