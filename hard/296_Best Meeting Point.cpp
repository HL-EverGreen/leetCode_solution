class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        // geometry
        // time complexity: O(n^2), space complexity: O(n)
        // 8ms, beats 100%
        
        // main idea:
        // Record all row_index and col_index of 1, and find median(in pos of [size/2]) of all row_index and col_index
        // The meeting point is just (median_row, median_col). Then compute the distance
        // 可以简化成一维想一想： 直线上n个点，找meeting point，肯定在最中间的点(奇数情况)，或中间两点任意一点(偶数情况)

        if(grid.empty() || grid[0].empty()) return 0;
        int row = grid.size(), col = grid[0].size(), res = 0;
        vector<int> posR, posC;
        
        for(int i = 0; i < row; i++) {                          // record all row and col pos of 1 
            for(int j = 0; j < col; j++) {
                if(grid[i][j] == 1) {
                    posR.push_back(i);
                    posC.push_back(j);
                }
            }
        }
        
        int med1 = posR[posR.size() / 2];                      // find median
        nth_element(posC.begin(), posC.begin() + posC.size() / 2, posC.end());
        int med2 = posC[posC.size() / 2];
        for(auto pos1 : posR) res += abs(pos1 - med1);         // compute distance
        for(auto pos2 : posC) res += abs(pos2 - med2);
        return res;
    }
};