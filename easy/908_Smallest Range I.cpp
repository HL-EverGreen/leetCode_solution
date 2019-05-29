class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 20ms, beats 94.4%
        
        // Main idea:
        // Since we could adjust 加数 in range of[-K, K], the greatest gap must
        // exists between original largest and smallest number.
        // So just find max and min value of the array, and compare 0 with it - 2 * K
        int minA = INT_MAX, maxA = INT_MIN;
        
        for(auto num : A) {
            minA = min(minA, num);
            maxA = max(maxA, num);
        }
        
        return max(0, maxA - minA - 2 * K);
    }
};