class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Use cur_width to record current width, and lines to record number of needed lines
        int cur_width = 0, lines = 0; 
        
        for(auto ch : S) {
            /* Add current width */
            cur_width += widths[ch - 'a'];
            
            /* Add lines if exceed 100 */
            lines += cur_width / 100;
            
            /* Readjust cur_width if exceed 100, or to 0 if equals 100 */
            cur_width = cur_width > 100 ? widths[ch - 'a'] : cur_width % 100;
        }
        lines += cur_width ? 1 : 0;         // Add one if cur_width > 0
        return {lines, cur_width};
    }
};