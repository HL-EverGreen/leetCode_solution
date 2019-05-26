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
    TreeNode* pruneTree(TreeNode* root) {
        // binary tree & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 0ms, beats 100%
        
        // Main idea:
        // Given a node, if left, right child are both null and its val is 0,
        // then it should be pruned. So return nullptr.
        if(!root) { return nullptr; }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(!root->left && !root->right && root->val == 0) { return nullptr; }
        return root;
    }
    
    
    // My method: may reduce unnecessary pointer expressions
    /*
    TreeNode* pruneTree(TreeNode* root) {
        prune(root);
        return root;
    }
    
    bool prune(TreeNode* root) {
        if(root == nullptr) { return true; }
        bool left = false, right = false;
        left = prune(root->left);
        right = prune(root->right);
        if(left) { root->left = nullptr; }
        if(right) { root->right = nullptr; }
        return left && right && (root->val == 0);
    }
    */
};