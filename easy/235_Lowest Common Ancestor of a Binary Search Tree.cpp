/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//recursive
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findLowestCommonAncestor(root,p,q);
    }
    
    TreeNode* findLowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(p->val<root->val && q->val<root->val)
            return findLowestCommonAncestor(root->left,p,q);
        else if(p->val>root->val && q->val>root->val)
            return findLowestCommonAncestor(root->right,p,q);
        else return root;
    }
};