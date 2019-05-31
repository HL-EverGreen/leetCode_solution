class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 99.11%
        
        // Main idea:
        // Two pass, one from left and one from right.
        // Just compare res[i] with distance between current index and last C position
        int size = S.length(), last_pos;
        vector<int> res(size, size);
        
        for(int i = 0, last_pos = -size; i < size; i++) {
            if(S[i] == C) { last_pos = i; }
            res[i] = min(res[i], abs(i - last_pos));
        }
        
        for(int i = size - 1, last_pos = -size; i >= 0; i--) {
            if(S[i] == C) { last_pos = i; }
            res[i] = min(res[i], abs(i - last_pos));
        }
        return res;
    }
};