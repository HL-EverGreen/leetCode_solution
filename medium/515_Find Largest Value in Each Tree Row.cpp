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
    vector<int> largestValues(TreeNode* root) {
        // DFS
        // time complexity: O(n), space complexity: O(1) + stack memory
        // beats 90%
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& res, int cur_depth) {
        if(root == nullptr) { return; }
        if(cur_depth == res.size()) { res.push_back(root->val); }
        else { res[cur_depth] = max(res[cur_depth], root->val); }
        dfs(root->left, res, cur_depth + 1);
        dfs(root->right, res, cur_depth + 1);
    }
};
