class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //dp
        //hp[i][j] represents minimum hp needed to pass dungeon[i][j]
        //so the goal is to calculate hp[0][0]
        //time complexity: O(row*col)
        
        int row = dungeon.size(), col = row == 0 ? 0 : dungeon[0].size();
        if(col == 0) return -1;
        
        //cause need to execute min(), so the initial value should be INT_MAX
        vector<vector<int>> hp(row + 1, vector<int>(col + 1, INT_MAX));
        
        //calculate minimum hp needed at each dungeon block
        hp[row][col - 1] = hp[row - 1][col] = 1;
        for(int cnt_row = row - 1; cnt_row >= 0; cnt_row--){
            for(int cnt_col = col - 1; cnt_col >= 0; cnt_col--){
                int need = min(hp[cnt_row + 1][cnt_col], hp[cnt_row][cnt_col + 1]) - dungeon[cnt_row][cnt_col];
                //if hp is excessive, hp always set to 1
                hp[cnt_row][cnt_col] = need <= 0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
};