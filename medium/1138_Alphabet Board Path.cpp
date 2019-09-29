class Solution {
public:
    string alphabetBoardPath(string target) {
        // matrix
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // We can transform the character into coordinate by doing /5 and %5.
        // So we can calculate the move plan based on current coord and next coord.
        // *NOTE: For moving to 'z', first move L/R and D. For moving from 'z', firt move U and L/R.
        //        So the append sequence is U -> L/R -> D
        
        string res;
        int last_x = 0, last_y = 0;
        
        for(auto& ch : target) {
            int x = (ch - 'a') / 5, y = (ch - 'a') % 5; // Get the coordinate
            res.append(string(max(0, last_x - x), 'U') + string(max(0, y - last_y), 'R')
                       + string(max(0, last_y - y), 'L') + string(max(0, x - last_x), 'D') + "!");  // Move to next coord
            last_x = x; last_y = y;
        }
        
        return res;
    }
};