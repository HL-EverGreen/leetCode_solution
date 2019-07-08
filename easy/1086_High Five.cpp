class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        // top k & partial sort
        // time complexity: O(mnlog5), n is the number of id, m is the length of record for each id
        // space complexity: O(mn)
        // 12ms, beats 93.7%
        
        // Main idea:
        // Use pq for top k sort, partial_sort can be substitute for pq, same time complexity but much less code.
        unordered_map<int, vector<int>> m;
        for(auto i : items) {
            m[i[0]].push_back(i[1]);
        }
        
        vector<vector<int>> res(m.size(), vector<int>());
        for(auto i : m) {
            partial_sort(i.second.begin(), i.second.begin() + 5, i.second.end(), greater<int>());
            res[i.first - 1].push_back(i.first);
            res[i.first - 1].push_back(accumulate(i.second.begin(), i.second.begin() + 5, 0) / 5);
        }
        return res;
    }
};