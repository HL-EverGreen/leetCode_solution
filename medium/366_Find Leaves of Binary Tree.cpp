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
    vector<vector<int>> findLeaves(TreeNode* root) {
        // DFS
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 4ms, beats 100%
        
        // main idea:
        // Get each node's height from bottom: cur = 1 + max(left, right)
        // And push node to corresponding vector
        vector<vector<int>> res;
        findLeaves(root, res);
        return res;
    }
    
    int findLeaves(TreeNode* root, vector<vector<int>>& res) {
        if(!root) return 0;
        int cur = 1 + max(findLeaves(root->left, res), findLeaves(root->right, res));
        if(res.size() < cur) res.push_back(vector<int>());
        res[cur - 1].push_back(root->val);
        return cur;
    }
};