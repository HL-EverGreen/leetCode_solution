class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        // array
        // time complexity: O(nlogn), space complexity: O(1)
        // 20ms, beats 98.94%
        
        // Key idea: apply +k or -k is same as apply 0 or +2k
        
        // Apply 2k to smallest element one by one, can only 2k to A[i] without appaying to a[j] where j < i
        sort(A.begin(), A.end());
        int res = A.back() - A[0], mx = A.back(), mn = A[0];
        for(int i = 0; i < A.size() - 1; i++) {
            mx = max(A[i] + 2 * K, mx);
            mn = min(A[0] + 2 * K, A[i + 1]);               // A[0] is because should apply to all A[j] which j <= i, so A[0] + 2*k must be the smallest among A[j] with index 0~i
            res = min(res, mx - mn);
        }
        return res;
    }
};