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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        // BST
        
        // Method 1: Recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 16ms, beats 91.59%
        
        // Main idea:
        // Each recursion, if current node is out of [L, R], call sub function to find node to replace current node.
        // If current node is in [L, R], continue call sub function to its left and right child.
        
        if(!root) return nullptr;
        if(root->val < L) return trimBST(root->right, L, R);    // Value out of range, replace current node
        if(root->val > R) return trimBST(root->left, L, R);
        root->left = trimBST(root->left, L, R);                 // Value in range, keep current node
        root->right = trimBST(root->right, L, R);
        return root;
        
        
        // Method 2: Iterative version
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 91.59%
        
        // Main idea:
        // Determine suitable root first.
        // And delete subtree if subtree's root's value is out of range.
        

        if(!root) return nullptr;

        // Find the proper root
        while(root) {
            if(root->val < L) root = root->right;
            else if(root->val > R) root = root->left;
            else break;
        }
        
        // Temporary pointer for left and right subtree
        TreeNode *lr = root;
        TreeNode *rr = root;
        
        // Remove the elements larger than L
        while(lr->left) {
            if(lr->left->val < L ) lr->left = lr->left->right;
            else lr = lr->left;     // If lr->left is in range, then all subtree under lr->left->right is in range
        }
        
         // Remove the elements larger than R
        while(rr->right) {
            if(rr->right->val > R) rr->right = rr->right->left;
            else rr = rr->right;    // If rr->right is in range, then all subtree under rr->right->left is in range
        }

        return root;
    }
};
