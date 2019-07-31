class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // array & greedy
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 92.58%
        
        // Main idea:
        // e.g. 报i的同色兔子最多出现i+1只，若i的数量大于i+1，则必须再加i+1
        unordered_map<int, int> m;
        for(auto v : answers) {
            m[v]++;
        }
        
        int res = 0;
        for(auto iter : m) {
            res += (iter.first + iter.second) / (iter.first + 1) * (iter.first + 1);
        }
        return res;
    }
};