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
    vector<int> inorderTraversal(TreeNode* root) {
        // binary tree
        // time complexity: O(n), space complexity: O(n) (recursion stack)
        // 0ms, beats 100%
        
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& res) {
        if(root) {
            inorderTraversal(root->left, res);
            res.push_back(root->val);
            inorderTraversal(root->right, res);
        }
    }
};