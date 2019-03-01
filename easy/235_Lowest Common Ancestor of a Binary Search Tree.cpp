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
        // BST
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 44ms, beats 97.9%
        
        // main idea:
        // find first root whose val is between q's val and p's val
        int root_val = root->val, p_val = p->val, q_val = q->val;
        if(root_val > p_val && root_val > q_val) return lowestCommonAncestor(root->left, p, q);
        else if(root_val < p_val && root_val < q_val) return lowestCommonAncestor(root->right, p, q);
        else return root;
        
    }
};