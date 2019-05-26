class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        // integer
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Just do it!
        vector<int> res;
           
        for(int i = left; i <= right; i++) {
            int cur = i;
            bool flg = true;
            while(cur) {
                int tmp = cur % 10;
                if(tmp == 0 || i % tmp != 0) {          // Not self dividing number, break
                    flg = false;
                    break;
                }
                cur /= 10;
            }
            if(flg) { res.push_back(i); }
        }
        return res;
    }
};