class Solution {
public:
    vector<int> constructRectangle(int area) {
        // math
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Straight forward, just attempt from sqrt(area)
        for(int i = sqrt(area); i >= 1; --i) {
            if(area % i == 0) return {area / i, i};
        }
        return {-1, -1};
    }
};