class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        // array & interval
        // time complexity: O(m+n), space complexity: O(1)
        // 44ms, beats 99%
        
        // Main idea:
        // Use two index to keep track of current position in A and B respectively.
        // And compare A[ia] and B[ib].
        vector<vector<int>> res;
        int aSize = A.size(), bSize = B.size();
        
        for(int ia = 0, ib = 0; ia < aSize && ib < bSize;) {
            vector<int> tempA = A[ia], tempB = B[ib];
            if(tempA[1] < tempB[0]) {
                ia++;
            } else if(tempA[0] > tempB[1]) {
                ib++;
            } else {
                res.push_back({max(tempA[0], tempB[0]), min(tempA[1], tempB[1])});
                if(tempA[1] > tempB[1]) {
                    ib++;
                } else {
                    ia++;
                }
            }
        }
        return res;
    }
};