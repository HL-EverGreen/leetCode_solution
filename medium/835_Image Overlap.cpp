class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        // matrix
        // time complexity: O(n^2), space complexity: O(n^2)
        // 52ms, beats 55.63%
        
        // Main idea:
        // Assign unique index for each block, and calculate distance between all
        // index in A and B. Select the highest frequency and return it.
        
        // Select 1 and assign unique index to it
        int N = A.size();
        vector<int> idxA, idxB;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(A[i][j] == 1) idxA.push_back(i * 100 + j);   
                if(B[i][j] == 1) idxB.push_back(i * 100 + j);
            }
        }
        
        // Get the highest frequency
        unordered_map<int, int> count;
        int res = 0;
        for(auto& a : idxA) {
            for(auto& b : idxB) {
                res = max(++count[a - b], res);
            }
        }
        
        return res;
    }
};