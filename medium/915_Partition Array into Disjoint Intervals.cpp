class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        // array & greedy
        // time complexity: O(n), space complexity: O(1)
        // 36ms, beats 97.15%
        
        // Main idea:
        // Attempt to set partition index as 0, and keep the local max value.
        // Compare local max to each new candidate:
        //   1) if local max > cand, means that the current partion is not correct. So set new partition and update local max.
        //   2) else, the current pratition is no problem. Update global max.
        
        int localMax = A[0], allMax = localMax;
        int partitionIdx = 0;
        int N = A.size();
        
        for(int i = 0; i < N; ++i) {
            if(localMax > A[i]) {   // Detect exception, try to set new partition (NOTE its guaranteed to have solution)
                localMax = allMax;
                partitionIdx = i;
            } else allMax = max(allMax, A[i]); // Current partition works, continue use it
        }
        return partitionIdx + 1;
    }
};