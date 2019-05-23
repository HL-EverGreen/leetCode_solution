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
    int rangeSumBST(TreeNode* root, int L, int R) {
        // BST & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 152ms, beats 86.17%
        // Main idea: Recursively find suitable range and update range respectively
        
        if(root == nullptr) { return 0; }
        int val = root->val;

        /* Too small, search right subtree */
        if(val < L) { return rangeSumBST(root->right, L, R); }

        /* Too large, search left subtree */
        if(val > R) { return rangeSumBST(root->left, L, R); }

        /* In range, adjust range to search in both left and right subtree */
        return val + rangeSumBST(root->left, L, val) + rangeSumBST(root->right, val, R);
    }
};