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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        // BST & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 0ms, beats 100%
        
        // Main idea:
        // Let res[1] be subtree > V, res[0] be subtree <= V.
        // Root must either be res[0] or res[1].
        // If root->val > V, root is res[1], and their might be subtree in left subtree who still > V. And root should set left to this subtree.
        // So the problem divides into splitBST() in left subtree.
        // So we can use recursive, since child problem has the same structure as parent problem.
        
        vector<TreeNode*> res(2, nullptr);
        if(!root) { return res; }
        
        if(root->val > V) {
            res[1] = root;
            auto tmp = splitBST(root->left, V);
            root->left = tmp[1];                       // Set subtree > V to root's left (might be NULL)
            res[0] = tmp[0];
        } else {
            res[0] = root;
            auto tmp = splitBST(root->right, V);
            root->right = tmp[0];                      // Set subtree <= V to root's right (might be NULL)
            res[1] = tmp[1];
        }
        return res;
    }
};