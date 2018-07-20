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
    vector<TreeNode*> res;
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || root->left==NULL) return root;
        iter(root->left,root->right,root);
        return res[0];
    }
    
    TreeNode* iter(TreeNode* par,TreeNode* leftChild, TreeNode* rightChild){
        if(par->left)
            iter(par->left,par->right,par);
        par->left=leftChild;
        par->right=rightChild;
        rightChild->left=NULL;//delete leaf's left&right
        rightChild->right=NULL;
        res.push_back(par);
        return par;
    }
};