class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // array
        // time complexity: O(n^2), space complexity: O(n)
        // 0ms, beats 100%
        
        // add up in place from right to left
        vector<int> new_line(rowIndex + 1, 1);
        for(int iter = 1; iter < rowIndex; iter++) {
            for(int pos = iter; pos >= 1; pos--) {
                new_line[pos] = new_line[pos] + new_line[pos - 1]; 
            }
        }
        return new_line;
    }
};