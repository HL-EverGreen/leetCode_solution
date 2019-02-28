class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 40ms, beats 90.86%
        
        // main idea:
        // Use hash table to record element's frequency and index of first appearance
        // When frequency > max_degree, update res and max_degree. When frequency == max_degree, compare res and cur min length
        
        if(nums.empty()) return 0;
        unordered_map<int, pair<int, int>> count;                       // key: (count, first appear index)
        int degree = 1, res = 1, size = nums.size();
        for(int i = 0; i < size; i++) {
            int val = nums[i];
            if(count.find(val) == count.end()) count[val] = {1, i};     // first appear
            else {
                int cur_degree = ++count[val].first;
                if(cur_degree > degree) {                               // largest frequency
                    degree = cur_degree;
                    res = i - count[val].second + 1;
                } else if(cur_degree == degree) res = min(res, i - count[val].second + 1);  // equal frequency
            }
        }
        return res;
    }
};