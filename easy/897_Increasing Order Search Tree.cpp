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
    TreeNode* increasingBST(TreeNode* root) {
        // binary tree & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 40ms, beats 90.25%
        
        // Inorder traverse the tree.
        // And use tail to record original parent node.
        // increasingBST(root->left) used to connect with former node.
        // increasingBST(root->right) used to connect with latter node.
        return increasingBST(root, nullptr);
    }
    
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};