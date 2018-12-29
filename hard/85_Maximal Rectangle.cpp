class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // array
        // time complexity: O(n^2), space complexity: O(n)
        // 20ms, beats 46.74%
        
        // main idea is to divide the matrix into each lines and transform into histogram
        // so the question transform to find max rectangle in histogram
        int row = matrix.size(), col = (row == 0 ? 0 : matrix[0].size()), res = 0;
        if(col == 0) { return 0; }
        vector<int> height(col, 0);
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    height[j]++;
                }
            }
            res = max(res, largestRectangle(height));
        }
        return res;
    }
    
    int largestRectangle(vector<int>& height) {
        int res = 0;
        stack<int> index;
        height.push_back(0);
        for(int i = 0; i < height.size(); i++) {
            while(!index.empty() && height[i] < height[index.top()]) {
                int h = height[index.top()];
                index.pop();
                int start_idx = index.empty() ? -1 : index.top();
                res = max(res, h * (i - start_idx - 1));
            }
            index.push(i);
        }
        return res;
    }
};