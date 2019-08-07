class Solution {
public:
    vector<int> constructArray(int n, int k) {
        // math & greedy
        // time complexity: O(n), space complexity: O(1)
        // 20ms, beats 96.16%
        
        // Main idea:
        // 1) When k == n - 1:
        //    out: 1 9 2 8 3 7 4 6 5
        //    dif:  8 7 6 5 4 3 2 1
        // 2) When k < n - 1:
        //    out: 1   9   2   8    3   4   5   6   7
        //    dif:   8   7   6   5    1   1   1   1 
        vector<int> res;
        int start = 1, end = n;
        while(k > 0) {
            res.push_back(k-- % 2 == 0 ? start++ : end--);
        }
        while(start <= end) {
            res.push_back(end--);
        }
        return res;
    }
};