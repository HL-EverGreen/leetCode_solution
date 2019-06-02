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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // binary tree & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 4ms, beats 99.03%
        
        // Main idea:
        // If the val > root->val, then val would become new root.
        // Otherwise, just branch into root->right, and find suitable position for val
        if(root == nullptr || root->val < val) {
            TreeNode* cur = new TreeNode(val);
            cur->left = root;
            return cur;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};