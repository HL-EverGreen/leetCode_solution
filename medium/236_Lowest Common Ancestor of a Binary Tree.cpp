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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // binary tree
        // time complexity: normal traverse time
        // 24ms, beats 100%
        
        // Main idea:
        // 1. return value are either NULL or possible lowest common ancestor
        // 2. if left is null, then return right
        // 3. if right is null, then return left
        // 4. if both are not null, return root
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left) return right;
        else if(!right) return left;
        else return root;
    }
};