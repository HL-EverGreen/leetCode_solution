class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // geometry
        // time complexity: O(1), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // See whether number of different length is 2
        unordered_set<int> len = {calDisSquare(p1, p2), calDisSquare(p1, p3), calDisSquare(p1, p4),
                                  calDisSquare(p2, p3), calDisSquare(p2, p4), calDisSquare(p3, p4)};
        return len.size() == 2 && !len.count(0);
    }
    
    /* Calculate the square of distance between two points */
    int calDisSquare(vector<int>& p1, vector<int>& p2) {
        return pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2); 
    }
};