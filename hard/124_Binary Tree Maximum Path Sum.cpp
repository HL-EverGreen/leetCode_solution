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
    int maxPathSum(TreeNode* root) {
        // binary tree
        // time complexity: O(n), space complexity: O(1)
        // 40ms, beats 99.5%
        
        // Main idea:
        // When entering a node, compare value containing this node's value to the res (since its children value has already been compared to the res)
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }
    
    int maxPathSum(TreeNode* root, int& res) {
        if(!root) return 0;
        int left = max(0, maxPathSum(root->left, res));
        int right = max(0, maxPathSum(root->right, res));
        res = max(res, root->val + left + right);                   // 比较每一个当该结点作为父节点时最大路径和的值(带左路径或右路径或都带或都不带)
        return root->val + max(left, right);                        // 返回包含该节点的一个路径(且该节点为路径的端点)
    }
};