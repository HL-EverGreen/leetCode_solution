class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        // hash table
        // time complexity: O(m + n), space complexity: O(min(m, n))
        // 100ms, beats 89.28%
        
        // Main idea:
        // Use hash table to record pos of restaurant of first list, and iterate in second list to find min index

        int m = list1.size(), n = list2.size();
        if(m > n) return findRestaurant(list2, list1);
        
        unordered_map<string, int> pos;
        vector<string> res;
        int minIdx = m + n - 1;

        // Record pos in the first list
        for(int i = 0; i < m; ++i) pos[list1[i]] = i;

        for(int i = 0; i < n; ++i) {
            string rest = list2[i];
            if(pos.count(rest)) {
                if(i + pos[rest] < minIdx) {
                    res = {rest};
                    minIdx = i + pos[rest];
                } else if(i + pos[rest] == minIdx) res.push_back(rest);
            }
        }
        return res;
    }
};