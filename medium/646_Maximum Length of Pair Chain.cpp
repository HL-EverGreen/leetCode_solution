class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // greedy
        // time complexity: O(nlogn), space complexity: O(1)
        // 60ms, beats 83.74%
        
        // Main idea:
        // Sort all pair in order whose end is smaller comes first.
        // Then simply pass the vector to find all suitable pair.
        if(pairs.size() == 0) { return 0; }
        
        /* p[1] small comes first */
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        
        /* Gready search */
        int res = 1, tail = pairs[0][1];
        for(auto p : pairs) {
            if(p[0] > tail) {
                res++;
                tail = p[1];
            }
        }
        return res;
    }
};