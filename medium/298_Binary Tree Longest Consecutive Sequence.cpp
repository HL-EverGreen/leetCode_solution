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
    int longestConsecutive(TreeNode* root) {
        int res=0;
        if(!root) return res;
        int temp=root->val;
        res=iter(root,res,temp-1);
        return res;
    }
    
    int iter(TreeNode* root, int res, int val){
        if(!root || root->val!=val+1)
            res=1;
        if(root->val==val+1)
            res++;
        int res1=0; 
        int res2=0;
        if(root->left)
            res1=iter(root->left,res,root->val);
        if(root->right)
            res2=iter(root->right,res,root->val);
        res=max(res,max(res1,res2));
        return res;
    }
};