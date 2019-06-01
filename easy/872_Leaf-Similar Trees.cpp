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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // binary tree
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 8ms, beats 84.49%
        
        // Main idea:
        // Straight forward, just do dfs to two trees
        string t1, t2;
        dfs(root1, t1);
        dfs(root2, t2);
        return t1 == t2;
    }
    
    void dfs(TreeNode* root, string& s) {
        if(!root) { return; }
        if(!root->left && !root->right) {
            s += root->val + '+';                   // Notice, should use special charcter to divide numbers
            return;
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
};