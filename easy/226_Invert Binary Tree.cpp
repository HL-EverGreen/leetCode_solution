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
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL||(root->left==NULL && root->right==NULL))
        //if(!root)
            return root;
        if(root->left!=NULL)
            invertTree(root->left);
        if(root->right!=NULL)
            invertTree(root->right);
        TreeNode* tempNode=NULL;
        tempNode=root->left;
        root->left=root->right;
        root->right=tempNode;
        return root;
        
    }
};