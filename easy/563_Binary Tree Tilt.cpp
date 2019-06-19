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
    int findTilt(TreeNode* root) {
        // binary tree
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 20ms, beats 89.95%
        
        // Main idea:
        // Preorder traverse tree, and calculate each node's subtree value sum.
        // Calculate res in each node.
        if(!root) { return 0; }
        int res = 0;
        pTraverse(root, res);
        return res;
    }
    
    int pTraverse(TreeNode* root, int& res) {
        if(!root) { return 0; }
        int leftSum = pTraverse(root->left, res);
        int rightSum = pTraverse(root->right, res);
        res += abs(leftSum - rightSum);
        return leftSum + rightSum + root->val;
    }
};