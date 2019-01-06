class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // dynamic programming
        // time complexity: O(row*col), space complexity: O(row*col)
        // 4ms, beats 99.8%
        
        // hp[i][j] represents minimum hp needed to pass dungeon[i][j]
        // so the goal is to calculate hp[0][0]
        // NOTICE: we can allocate size + 1 space instead of size space so that we need not to include several $if$ in loop
        int row = dungeon.size(), col = (row == 0 ? 0 : dungeon[0].size());
        if(col == 0) { return -1; }
        
        // cause need to execute min(), so the initial value should be INT_MAX
        vector<vector<int>> min_hp(row + 1, vector<int>(col + 1, INT_MAX));
        min_hp[row][col - 1] = min_hp[row - 1][col] = 1;
        
        // calculate minimum hp needed at each dungeon block
        for(int i = row - 1; i >= 0; i--) {
            for(int j = col - 1; j >= 0; j--) {
                int need = min(min_hp[i + 1][j], min_hp[i][j + 1]) - dungeon[i][j];
                //if hp is excessive, hp always set to 1
                min_hp[i][j] = (need <= 0 ? 1 : need);
            }
        }
        return min_hp[0][0];
    }
};