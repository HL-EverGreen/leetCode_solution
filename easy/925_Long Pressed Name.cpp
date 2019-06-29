class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // two pointers
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Use mi and ni to present current index in two vector to comp with each other.
        int m = name.length(), n = typed.length();
        int mi = 0, ni = 0;
        for (; ni < n; ++ni) {
            if(mi < m && name[mi] == typed[ni]) {
                mi++;
            } else if(!ni || typed[ni] != typed[ni - 1]) {
                return false;
            }
        }
        return mi == m;             // Check if use out of `name`
    }
};