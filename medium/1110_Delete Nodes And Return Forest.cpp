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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // DFS & binary tree
        // time complexity: O(n), space complexity: O(n) + stack memory
        // 16ms, beats 98.38    %
        
        // Main idea:
        // Use dfs, if parent is deleted and current node is not deleted, push into res
        vector<TreeNode*> res;
        unordered_set<int> target(to_delete.begin(), to_delete.end());
        dfs(res, root, target, true);
        return res;
    }
    
    TreeNode* dfs(vector<TreeNode*>& res, TreeNode* root, unordered_set<int>& target, bool is_par_del) {
        if(!root) { return nullptr; }
        if(target.count(root->val)) { 
            is_par_del = true;
        } else {
            if(is_par_del) { res.push_back(root); }             // Push into res if parent is deleted and current node is not deleted
            is_par_del = false;
        }
        root->left = dfs(res, root->left, target, is_par_del);
        root->right = dfs(res, root->right, target, is_par_del);
        return is_par_del ? nullptr : root;                     // Return nullptr if node is deleted
    }
};