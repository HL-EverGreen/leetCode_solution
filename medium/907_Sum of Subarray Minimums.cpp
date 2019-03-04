class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        // array & stack
        // time complexity: O(n), space complexity: O(n)
        // 104ms, beats 40%
        
        // main idea:
        // pair<int, int> represent: <value, number of number greater than this value in left/right>
        // Store pair from left or right in stack, and calculate current pair
        // Res can be computed as: sum of (A[i] * left[i] * right[i]), 需要加A[i]的总组合数为左连续数乘右连续数
        
        int N = A.size(), mod = 1e9 + 7;
        stack<pair<int, int>> s1, s2;
        vector<int> left(N), right(N);
        
        for(int i = 0; i < N; i++) {                                                // compute 左连续数
            int count = 1;
            while(!s1.empty() && s1.top().first > A[i]) {
                count += s1.top().second;
                s1.pop();
            }
            s1.push({A[i], count});
            left[i] = count;
        }
        
        for(int i = N - 1; i >= 0; i--) {                                           // compute 右连续数
            int count = 1;
            while(!s2.empty() && s2.top().first >= A[i]) {
                count += s2.top().second;
                s2.pop();
            }
            s2.push({A[i], count});
            right[i] = count;
        }
        
        int res = 0;
        for(int i = 0; i < N; i++) res = (res + A[i] * left[i] * right[i]) % mod;   // compute result
        return res;
    }
};