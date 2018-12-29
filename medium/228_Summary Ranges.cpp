class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // use start and end every turn, if nums[end + 1] == nums[end] + 1, end++
        // case 1: end > start, then contain "->"
        // case 2: end == start, then single number
        
        vector<string> res;
        int start, end;
        for(int i = 0; i < nums.size();) {
            start = end = i;
            while(end + 1 < nums.size() && nums[end + 1] == nums[end] + 1) { end++; }
            if(end > start) { 
                res.push_back(to_string(nums[start]) + "->" + to_string(nums[end])); 
            } else {
                res.push_back(to_string(nums[end]));
            }
            i = end + 1;
        }
        return res;
    }
};