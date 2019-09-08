class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // array & two directions
        // time complexity: O(n), space complexity: O(n)
        // 40ms, beats 100%
        
        // Main idea:
        // Similar to production except self. We can calculate max sum subarray from two sides.
        // fw[i] means that the max sum of subarray ending in arr[i] (left to right)
        // bw[i] means that the max sum of subarray ending in arr[i] (right to left)
        // So fw[i - 1] + bw[i + 1] is the max sum of subarray with deleting arr[i]
        // *note: Since can choose not delete element, we still need to calculate max sum of subarray
        int n = arr.size();
        if(n == 1) return arr[0];
        vector<int> fw(n), bw(n);
        
        int res = INT_MIN;
        int sum = 0, backSum = 0;
        for(int i = 0; i < n; ++i) {
            sum += arr[i];
            res = max(res, sum);            // Calculate max sum of continous subarray without deleting any element
            fw[i] = sum;
            sum = max(sum, 0);
            
            int backIdx = n - 1 - i;
            backSum += arr[backIdx];
            bw[backIdx] = backSum;
            backSum = max(backSum, 0);
        }
        
        for(int i = 1; i < n - 1; ++i) {    // Delete arr[i]
            res = max(res, fw[i - 1] + bw[i + 1]);
        }
        return res;
    }
};