class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 40ms, beats 98.63%
        
        int count[26] = {0};
        int max_cnt = 0, res;
        for(auto t : tasks) {
            count[t - 'A']++;
            max_cnt = max(max_cnt, count[t - 'A']);
        }
        res = (max_cnt - 1) * (n + 1);
        for(int i = 0; i < 26; i++) {
            if(count[i] == max_cnt) res++;
        }
        return max(res, (int)tasks.size());                 // vector::size() return type is size_type, is unsigned int
    }
};