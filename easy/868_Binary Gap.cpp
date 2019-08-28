class Solution {
public:
    int binaryGap(int N) {
        // bit
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Record gap from last '1'
        int last = -32, res = 0;        // `last` is 足够小的值
        while(N) {
            if(N & 1) {
                res = max(res, last);
                last = 0;
            }
            ++last;
            N >>= 1;
        }
        return res;
    }
};