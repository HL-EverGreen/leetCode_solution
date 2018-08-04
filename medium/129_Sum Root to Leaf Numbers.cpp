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
    int sumNumbers(TreeNode* root) {//recursive
        int res=0;
        if(!root) return res;
        sum(root,0,res);
        return res;
    }
    
    void sum(TreeNode* root, int par_val, int& res){
        if(root->left)
            sum(root->left,par_val*10+root->val,res);
        if(root->right)
            sum(root->right,par_val*10+root->val,res);
        if(!root->left && !root->right){
            res+=10*par_val+root->val;      
        }
    }
};