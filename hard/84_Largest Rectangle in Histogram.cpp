class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // array & stack
        // time complexity: O(n)
        // 8ms, beats 98.43%
        
        // when current heights[i] <= heights[index.top()], calculate new possible rectangle
        int res = 0;
        stack<int> index;
        heights.push_back(0);
        
        for(int i = 0; i < heights.size(); i++) {
            while(index.size() > 0 && heights[i] <= heights[index.top()]) {
                int h = heights[index.top()];
                index.pop();
                
                int left_idx = (index.empty() ? -1 : index.top());
                res = max(res, h * (i - left_idx - 1));
            }
            index.push(i);
        }
        return res;
    }
};