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
    int countUnivalSubtrees(TreeNode* root) {
        int res=0;
        if(root)
            iter(root, root->val, res);
        return res;
    }
    
    bool iter(TreeNode* root, int val, int& count){//recursive
        if(root==nullptr) return true;
        bool b1=iter(root->left, root->val, count);
        bool b2=iter(root->right, root->val, count);
        if(b1 && b2) count++;
        return val==root->val && b1 && b2;
    }
};