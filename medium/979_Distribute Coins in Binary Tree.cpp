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
    int totalMove = 0;
    int distributeCoins(TreeNode* root) {
        // Binary tree & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 4ms, beats 98.46%
        
        // Main idea:
        // Calculate each node's required moves between itself and its left child and right child respectively.
        // Notice: May occur negative, so should use abs() when calculate sum
        dfs(root);
        return totalMove;
    }
    
    int dfs(TreeNode* root) {
        if(!root) { return 0; }
        int left = dfs(root->left), right = dfs(root->right);
        totalMove += abs(left) + abs(right);
        return root->val + left + right - 1;
    }


    /* Recursive but no global variable version */
    /*
    int distributeCoins(TreeNode* root) {
        int res = 0;
        if (root->left) {
            res += distributeCoins(root->left);
            root->val += root->left->val - 1;
            res += abs(root->left->val - 1);
        }
        if (root->right) {
            res += distributeCoins(root->right);
            root->val += root->right->val - 1;
            res += abs(root->right->val - 1);
        }
        return res;
    }
    */
};