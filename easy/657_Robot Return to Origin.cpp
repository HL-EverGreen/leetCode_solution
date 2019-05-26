class Solution {
public:
    bool judgeCircle(string moves) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 95.24%
        
        // Main idea:
        // Use row offset and col offset to record the robot's move offset
        int rowOffset = 0, colOffset = 0, size = moves.size();
        for(auto move : moves) {
            switch(move) {
                case 'U': colOffset++; break;
                case 'D': colOffset--; break;
                case 'R': rowOffset++; break;
                case 'L': rowOffset--; break;
            }    
        }
        return !(rowOffset | colOffset);
    }
};