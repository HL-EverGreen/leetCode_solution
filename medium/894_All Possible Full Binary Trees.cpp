/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> cache;
    
    vector<TreeNode*> allPossibleFBT(int N) {
        // binary tree & divide and conquer
        // 84ms, beats 99.92%
        
        // Main idea:
        // Use unordered_map to cache calculated result.
        // Divide problem into two subproblem (left subtree and right subtree).

        // Notice: if doesn't want to get frankenstein tree, each time connect subtree
        // from the subproblem's result, should deeply clone the original tree and then connect!

        /* Find in cache, directly return */
        if(cache.count(N)) { return cache[N]; }
        
        vector<TreeNode*> res;
        if(N == 1) {
            res.push_back(new TreeNode(0));
        } else if(N % 2 == 1) {                                         // Only calculate for odd numbers
            for(int i = 1; i < N; i += 2) {
                vector<TreeNode*> left = allPossibleFBT(i);
                vector<TreeNode*> right = allPossibleFBT(N - 1 - i);
                for(int j = 0; j < left.size(); j++) {
                    for(int k = 0; k < right.size(); k++) {
                        TreeNode* cur = new TreeNode(0);
                        cur->left = left[j];
                        cur->right = right[k];
                        res.push_back(cur);
                    }
                }
            }
        }
        /* Cache current result */
        cache[N] = res;
        return res;
    }
};