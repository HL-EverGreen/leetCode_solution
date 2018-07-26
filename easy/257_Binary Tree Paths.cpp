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
    vector<string> binaryTreePaths(TreeNode* root) {//dfs
        string temp="";
        if(root) temp+=to_string(root->val);
        vector<string> res;
        dfs(root,res,temp);
        return res;
    }
    
    void dfs(TreeNode* root, vector<string>& res, string temp){
        if(root){
            if(!root->left && !root->right){
                res.push_back(temp);
                return;
            }
            if(root->left)
                dfs(root->left,res,temp+"->"+to_string(root->left->val));
            if(root->right)
                dfs(root->right,res,temp+"->"+to_string(root->right->val));
        }
    }
};