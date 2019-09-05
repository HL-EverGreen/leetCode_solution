class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // geometry
        // time complexity: O(1), space complexity: O(1)
        // 0ms, beats 100%
        
        // Compare bottom-left corner with top-right corner
        if(rec1[0] >= rec2[2] || rec1[1] >= rec2[3] ||
           rec1[2] <= rec2[0] || rec1[3] <= rec2[1]) return false;
        return true;
    }
};