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
    bool isUnivalTree(TreeNode* root) {
        // Binary tree & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 0ms, beats 100%
        
        // Main idea:
        // Straight forward: current node true = left subtree true && right subtree true && left equal && right equal
        return (!root->left || (root->left->val == root->val && isUnivalTree(root->left))) &&
            (!root->right || (root->right->val == root->val && isUnivalTree(root->right)));
    }
};