class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        // array
        // time complexity: O(m^2), m is the # of different elements in A, space complexity: O(m)
        // 12ms, beats 76.27%
        
        // Main idea:
        // Count value for elements in A, then iterate through hash table.
        // Using combination math to calculate the result.
        
        long res = 0;
        unordered_map<int, int> dict;
        for(const auto& a : A) ++dict[a];
        
        for(const auto& it1 : dict) {
            for(const auto& it2 : dict) {
                int i = it1.first, j = it2.first, k = target - i - j;
                if(dict.count(k) == 0) continue;
                if(i == j && j == k) res += (long)dict[i] * (dict[i] - 1) * (dict[i] - 2) / 6;    // Three same
                else if(i == j && j != k) res += (long)dict[i] * (dict[i] - 1) / 2 * dict[k];     // Two same
                else if(i < j && j < k) res += (long)dict[i] * dict[j] * dict[k];                 // No same, use < to ensure only compute once
            }
        }
        return res % int(1e9 + 7);
    }
};