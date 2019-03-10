class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 100%
        
        // main idea:
        // Record first state, and use cycle to record length of cycle
        // If encounter same state again, can directly divide by cycle to avoid unnecessary computation
        
        int size = cells.size(), cycle = 0;
        vector<int> ini;
        for(N--; N >= 0; N--, cycle++) {
            for(int i = 1; i < size - 1; i++) {
                cells[i] |= ((!((cells[i - 1] & 1) ^ (cells[i + 1] & 1))) << 1);
            }
            for(auto& num : cells) num >>= 1;
            if(cycle == 0) ini = cells;
            else if(ini == cells) N %= cycle;
        }
        return cells;
    }
};