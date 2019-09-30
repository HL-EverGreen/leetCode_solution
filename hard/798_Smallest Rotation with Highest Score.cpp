class Solution {
public:
    int bestRotation(vector<int>& A) {
        // DP
        // time complexity: O(n), space complexity: O(n)
        // 32ms, beats 82.31%
        
        // Main idea:
        // All we care about is to calculate how the score would change from K to K + 1
        //   1) Get point: Each shift can gain one point (by moving index 0 to index N - 1)
        //   2) Lose point: We calculate for each K that how many elements start to lose point at this K.
        // So when K++, we calculate the relative points according to K's point. So there is no need to calculate index 0's point.
        
        int N = A.size();
        int change[N] = {0};
        
        // Loop for all elements in A to compute its max index where start losing point
        for(int i = 0; i < N; ++i) change[(i - A[i] + 1 + N) % N] -= 1;
        
        // Loop for all positions start from 1
        for(int i = 1; i < N; ++i) change[i] += change[i - 1] + 1;
        
        // Return the max one
        return distance(change, max_element(change, change + N));
    }
};