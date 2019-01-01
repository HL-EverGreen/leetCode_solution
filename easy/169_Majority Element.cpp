class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // array
        
        // method 1
        // using hash table
        // time complexity: O(n), space complexity: O(n)
        // 12ms, beats 98.42%
        unordered_map<int, int> count;
        int n_size = nums.size();
        for(int num : nums) {
            if(++count[num] > n_size / 2) {
                return num;
            }
        }
        
        // method 2
        // Moore Voting algorithm
        // time complexity: O(n), space complexity: O(1)
        // 12ms, beats 98.42%
        /*
        int major, count = 0;
        for(int num : nums) {
            if(!count) {
                major = num;
                count++;
            } else {
                count += (major == num ? 1 : -1);
            }
        }
        return major;
        */
    }
};