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
    int findBottomLeftValue(TreeNode* root) {
        // DFS
        // time complexity: O(n), space complexity: O(n) + stack memory
        // beats 90%
        int res = root->val, max_depth = 0;
        dfs(root, res, max_depth, 0);
        return res;     
    }

    void dfs(TreeNode* root, int& res, int& max_depth, int cur_depth) {
        if(root == nullptr) { return; }
        if(cur_depth > max_depth) {
            max_depth = cur_depth;
            res = root->val;
        }
        dfs(root->left, res, max_depth, cur_depth + 1);
        dfs(root->right, res, max_depth, cur_depth + 1);
    }
};
