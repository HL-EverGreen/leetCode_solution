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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // binary tree
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 4ms, beats 79.02%
        
        // Main idea:
        // First player choose a node, and at most has three subtrees (its parent, its left child and its right child)
        // Second player can take one of these subtrees, and first player owns the rest two subtrees and the first node.
        // So just need to figure whether there is a subtree whose number of nodes > n/2
        
        int left = 0, right = 0;
        count(root, x, left, right);    // Count number of nodes in left subtree and right subtree
        return left > n / 2 || right > n / 2 || (n - 1 - left - right) > n / 2;
    }
    
    // Count number of nodes in left subtree and right subtree
    // for a given node whose value is target
    int count(TreeNode* root, int target, int& left, int& right) {
        if(!root) return 0;
        int l = count(root->left, target, left, right);
        int r = count(root->right, target, left, right);
        if(root->val == target) {
            left = l;
            right = r;
        }
        return 1 + l + r;
    }
};