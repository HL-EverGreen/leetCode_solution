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
    int maxPathSum(TreeNode* root) { //binary tree
        int res=INT_MIN;
        findMaxPath(root,res);
        return res;
    }
    
    int findMaxPath(TreeNode* root, int& res){
        if(!root) return 0;
        int left=max(0,findMaxPath(root->left, res));
        int right=max(0,findMaxPath(root->right, res));
        res=max(res, left+right+root->val);  //比较每一个当该结点作为父节点时最大路径和的值(带左路径或右路径或都带或都不带)
        return max(left, right)+root->val;   //返回包含该节点的一个路径(且该节点为路径的端点)
    }
};