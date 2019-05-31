class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 164ms, beats 86.8%
        
        // Main idea:
        // Keep updating sum of real time even number
        int sum = 0;
        vector<int> res;
        
        for(auto num : A) {
            if(num % 2 == 0) { sum += num; }
        }
        
        for(auto qs : queries) {
            int idx = qs[1];
            if(A[idx] % 2 == 0) { sum -= A[idx]; }              // Remove current even number from sum
            A[idx] += qs[0];
            if(A[idx] % 2 == 0) { sum += A[idx]; }              // Add if still even number
            res.push_back(sum);
        }
        return res;
    }
};