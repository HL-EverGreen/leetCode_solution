class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        // array
        // time complexity: O(1), space complexity: O(n)
        // 272ms, beats 82.33%
        
        // Intuitive
        unordered_set<int> s(candies.begin(), candies.end());
        return min(s.size(), candies.size() / 2);
    }
};