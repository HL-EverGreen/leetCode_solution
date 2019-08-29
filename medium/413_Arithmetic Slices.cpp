// array & dp

// Original solution
// time complexity: O(n), space complexity: O(1)
// 0ms, beats 100%
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        int res = 0;
        int len = 2;
        int last = A[1] - A[0];
        
        for(int i = 2; i < n; ++i) {
            int diff = A[i] - A[i - 1];
            if(diff == last) ++len;
            else {
                res += calSubsetNum(len);
                len = 2;
                last = diff;
            }
        }
        res += calSubsetNum(len);
        return res;
    }
    
    /* Calculate all subset number with set's length equals n */
    int calSubsetNum(int n) {
        if(n < 3) return 0;
        return (n - 1) * (n - 2) / 2;
    }
};

// Updated solution
// *Use cur to present number of arithmetic sequence ends at current position, cound refer to dp[i] in below DP solution
// time complexity: O(n), space complexity: O(1)
// 0ms, beats 100%
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        int res = 0;
        int cur = 0;
        int last = A[1] - A[0];
        
        for(int i = 2; i < n; ++i) {
            int diff = A[i] - A[i - 1];
            if(diff == last) res += ++cur;
            else {
                last = diff;
                cur = 0;
            }
        }
        return res;    
    }
};

// or DP version, though meaningless, but could see the meaning of dp[i]
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        vector<int> dp(n, 0); // dp[i] means the number of arithmetic slices ending with A[i]
        if (A[2]-A[1] == A[1]-A[0]) dp[2] = 1; // if the first three numbers are arithmetic or not
        int result = dp[2];
        for (int i = 3; i < n; ++i) {
            // if A[i-2], A[i-1], A[i] are arithmetic, then the number of arithmetic slices ending with A[i] (dp[i])
            // equals to:
            //      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
            //      +
            //      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
            // it is how dp[i] = dp[i-1] + 1 comes
            if (A[i]-A[i-1] == A[i-1]-A[i-2]) 
                dp[i] = dp[i-1] + 1;
            result += dp[i]; // accumulate all valid slices
        }
        return result;
    }
};