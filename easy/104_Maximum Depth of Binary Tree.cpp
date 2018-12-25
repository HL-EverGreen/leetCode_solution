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
    // binary tree

    // method 1
    // Time Complexity: O(n)
    // Bottom up
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        } else return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    // method 2
    // Time complexity: O(n)
    // 4ms, beats 98.89%
    // Top down
    /*
    int maxDepth(TreeNode* root) {
        int max_depth = 0, cur_depth = 0;
        curMaxDepth(root, max_depth, cur_depth);
        return max_depth;
    }
    
    void curMaxDepth(TreeNode* root, int& max_depth, int cur_depth) {
        if(root != nullptr) {
            cur_depth++;
            max_depth = max(max_depth, cur_depth);
            curMaxDepth(root->left, max_depth, cur_depth);
            curMaxDepth(root->right, max_depth, cur_depth);
        }
    }
    */
};