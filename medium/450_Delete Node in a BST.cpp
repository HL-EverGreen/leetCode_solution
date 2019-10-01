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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // BST & recursive
        // time complexity: O(logn), space complexity: O(1) + stack memory
        // 28ms, beats 94.03%
        
        // Main idea:
        // Straight forward recursive.
        // If find node to delete, if its right child is null, return left child.
        // If right child exists, move left child to be left child of leftmost node of the right child's subtree.
        
        if(!root) return nullptr;
        
        if(root->val == key) {  // Find node
            if(!root->right) return root->left;
            else {      // Move left child to suitable position in subtree whose root is the right child
                TreeNode* tmp = root->right;
                while(tmp->left) tmp = tmp->left;   // Find leftmost node
                tmp->left = root->left;
                return root->right;
            }
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else root->right = deleteNode(root->right, key);
        return root;
    }
};