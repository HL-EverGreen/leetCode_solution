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
    TreeNode* prev;
    void flatten(TreeNode* root) {
        // binary tree

        // recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 4ms, beats 93.37%
        
        // reverse preorder traversal, set prev and update continually
        if(!root) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
        
        // iterative
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 93.37%
        TreeNode* cur = root;
        while(cur) {
            if(cur->left) { // If has left subtree, find rightmost node and set its right child to cur->right. 
                            // Then adjust cur->left to cur->right.
                TreeNode* prev = cur->left;
                while(prev->right) prev = prev->right;
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};