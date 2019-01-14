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
    bool isValidBST(TreeNode* root) {
        // BST & recursive
        // 8ms, beats 97.05%
        
        // use maxNode and minNode to compare with current node's value
        return isValidBST(root, NULL, NULL);
    }
    
    bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(!root) { return true; }
        if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val)) { return false; }
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};