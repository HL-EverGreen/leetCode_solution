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
    string tree2str(TreeNode* t) {
        // binary tree & string
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 12ms, beats 98.34%
        
        // dfs
        string res;
        dfs(t, res);
        return res;
    }
    
    /* Do dfs on binary tree and construct the string */
    void dfs(TreeNode* root, string& res) {
        if(!root) return;
        res.append(to_string(root->val));
        if(root->left) {
            res.push_back('(');
            dfs(root->left, res);
            res.push_back(')');
        } else if(root->right) res.append("()");        // Only has right child, append () for null left child
        if(root->right) {
            res.push_back('(');
            dfs(root->right, res);
            res.push_back(')');
        }
    }
};