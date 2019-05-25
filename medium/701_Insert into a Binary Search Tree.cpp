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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // BST
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 96ms, beats 83.66%
        
        // Method 1: recursive
        // Main idea:
        // Continue search until find nullptr node, and replace this node with val
        if(root == nullptr) { return new TreeNode(val); }
        if(val > root->val) { 
            root->right = insertIntoBST(root->right, val); 
        } else { 
            root->left = insertIntoBST(root->left, val); 
        }
        return root;
        

        // Method 2: iterative
        /*
        TreeNode *cur = root, *node = new TreeNode(val);
        
        while(cur) {
            if(cur->val < val) {
                if(cur->right) {
                    cur = cur->right;
                } else {
                    cur->right = node;
                    break;
                }
            } else {
                if(cur->left) {
                    cur = cur->left;
                } else {
                    cur->left = node;
                    break;
                }
            }
        }
        
        return root ? root : node;
        */
     }
};