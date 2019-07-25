class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        vector<int> res(num_people);
        for(int idx = 0; candies > 0; candies -= ++idx) {
            res[idx % num_people] += min(idx + 1, candies);
        }
        return res;
    }
};