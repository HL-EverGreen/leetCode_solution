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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // binary tree
        // time complexity: normal traverse time
        // space complexity: O(n) to store new tree
        // 48ms, beats 99%
        
        if(!t1 && !t2) return nullptr;
        int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0);
        TreeNode* root = new TreeNode(val);
        root->left = mergeTrees((t1 ? t1->left : nullptr), (t2 ? t2->left : nullptr));
        root->right = mergeTrees((t1 ? t1->right : nullptr), (t2 ? t2->right : nullptr));
        return root;
        
        // another logic
        /*
        if ( t1 && t2 ) {
            TreeNode * root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
            return root;
        } else {
            return t1 ? t1 : t2;
        }
        */
    }
};