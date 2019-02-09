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
    int diameterOfBinaryTree(TreeNode* root) {
        // binary tree
        // time complexity: normal traverse time, space complexity: O(1) + stack memory
        // 20ms, beats 100%
        
        int res = 0;
        diameterOfBinaryTree(root, res);
        return res;
    }
    
    // return root's subtree max height, as well as keep max diameter
    int diameterOfBinaryTree(TreeNode* root, int& maxDia) {
        if(!root) return 0;
        int left = diameterOfBinaryTree(root->left, maxDia);
        int right = diameterOfBinaryTree(root->right, maxDia);
        maxDia = max(maxDia, left + right);
        return max(left, right) + 1;
    }
};