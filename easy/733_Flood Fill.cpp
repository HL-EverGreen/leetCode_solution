class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // DFS
        // 28ms, beats 99.51%
        
        // main idea:
        // Do DFS from (sr, sc), if enter block which already has been painted, return
        
        int color = image[sr][sc];
        floodFill(image, sr, sc, color, newColor);
        return image;
    }
    
    void floodFill(vector<vector<int>>& image, int sr, int sc, int color, int newColor) {
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] == newColor || image[sr][sc] != color) return;
        image[sr][sc] = newColor;
        floodFill(image, sr + 1, sc, color, newColor);
        floodFill(image, sr - 1, sc, color, newColor);
        floodFill(image, sr, sc + 1, color, newColor);
        floodFill(image, sr, sc - 1, color, newColor);
    }
};