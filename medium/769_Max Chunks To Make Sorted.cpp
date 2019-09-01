class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // array & bucket
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Repeatedly update maximum number up to now, and if current max number
        // equals to current index, place one bucket.
        int max_i = 0;
        int res = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            max_i = max(max_i, arr[i]);
            if(max_i == i) ++res;
        }
        return res;
    }
};