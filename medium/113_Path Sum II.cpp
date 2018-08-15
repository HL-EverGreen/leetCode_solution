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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {//dfs
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res,tmp,root,sum);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& tmp, TreeNode* root, int sum){//might exist negative number so traverse every path
        if(root){
            tmp.push_back(root->val);
            if(!root->left && !root->right && sum-root->val==0){
                res.push_back(tmp);
                tmp.pop_back();
                return;
            }
            dfs(res,tmp,root->left,sum-root->val);
            dfs(res,tmp,root->right,sum-root->val);
            tmp.pop_back();
        }
    }
};