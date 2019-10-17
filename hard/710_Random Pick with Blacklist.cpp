class Solution {
public:
    Solution(int N, vector<int>& blacklist) {
        // design & map
        // time complexity: O(n) for Solution(), O(1) for pick()
        // time complexity: O(m), m is the size of blacklist
        // 220ms, beats 63.04%
        
        // Main idea:
        // Condense N array into N - blacklist.size() array.
        // So we need to remap number in blacklist and also < (N - blacklist.size()) to valid number >= (N - blacklist.size())
        // When random pick, if the number is remapped, return the remap value. Else directly return
        
        M = N - blacklist.size();
        for(const auto& b : blacklist) m[b] = -1;
        for(const auto& b : blacklist) {
            if(b < M) {
                while(m.count(N - 1)) --N;      // Find valid largest number currently
                m[b] = N - 1;                   // Remap
                --N;
            }
        }
    }
    
    int pick() {
        int idx = rand() % M;
        if(m.count(idx)) return m[idx];
        else return idx;
    }
private:
    int M;
    unordered_map<int, int> m;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */