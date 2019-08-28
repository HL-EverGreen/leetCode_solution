class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // vector
        // time: O(nlogn), space: O(n)
        
        int res = 0, n = heights.size();
        vector<int> origin = heights;
        sort(heights.begin(), heights.end());
        for(int i = 0; i < n; ++i) {
            if(heights[i] != origin[i]) ++res;
        }
        return res;
    }
};