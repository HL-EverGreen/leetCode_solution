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
    int widthOfBinaryTree(TreeNode* root) {
        // binary tree
        // time complexity: O(n), space complexity: O(logn) + stack memory
        // 0ms, beats 100%
        
        // Main idea: Preorder traversal
        // If cur node's id is i, its left child id is 2 * i, right child is 2 * i + 1 (if root id starts at 1)
        // Keep leftmost index, and compare each same level node's value - leftmost value with max width
        // *NOTICE: Use this id schema will lead id to be very large, cause overflow.
        // Though change to double can handle this issue, but think about other way to avoid this!
        
        vector<double> v;
        return dfs(root, 0, 1, v);
    }
    
    // Preorder traversal, if current node is the first node in current level, then set the leftmost value
    // Else, compare val - leftmost val with max width
    double dfs(TreeNode* root, int level, double order, vector<double>& v) {
        if(!root) return 0;
        if(v.size() == level) v.push_back(order);   // Leftmost value
        return max({order - v[level] + 1, dfs(root->left, level + 1, 2 * order, v),
                   dfs(root->right, level + 1, 2 * order + 1, v)});             // Return max width for nodes in this subtree
    }
};
