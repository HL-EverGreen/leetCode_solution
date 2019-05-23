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
    int restSum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        // BST & recusive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // Main idea: Traverse according to right_subtree -> current_node -> left_subtree.
        // Update restSum and current node's value continually
        
        if(!root) { return nullptr; }
        bstToGst(root->right);
        restSum = (root->val += restSum);       // Update
        bstToGst(root->left);
        return root;
    }
};