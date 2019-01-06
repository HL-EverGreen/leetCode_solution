class Solution {
public:
    int numTrees(int n) {
        // dynamic programming
        // time complexity: O(n^2), space complexity: O(n)
        // 0ms, beats 100%
        
        // number of nodes on left side of root: from 0 ~ i - 1
        if(n < 1) { return 0; }
        vector<int> uni_bst_num(n + 1, 0);
        uni_bst_num[0] = uni_bst_num[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                uni_bst_num[i] += uni_bst_num[j] * uni_bst_num[i - j - 1];
            }
        }
        return uni_bst_num[n];
    }
};