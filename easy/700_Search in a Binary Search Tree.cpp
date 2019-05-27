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
    TreeNode* searchBST(TreeNode* root, int val) {
        // BST & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 52ms, beats 92.25%
        
        // Main idea:
        // Search node by node based on BST's property
        if(!root) { return nullptr; }
        if(root->val == val) { return root; }
        else if(root->val > val) { return searchBST(root->left, val); }
        else { return searchBST(root->right, val); }
    }
};