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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // binary tree & recursive
        // time complexity: O(n^2), space complexity: O(1) + stack memory
        // 0ms, beats 100%
        
        // Main idea:
        // 1) If one node is null but another isn't, return false
        // 2) If both nodes are null, return true
        // 3) If both nodes are not null, compare their values and branch the problem into four subproblems. 
        if((root1 && !root2) || (!root1 && root2)) {        // One of them is Null
            return false; 
        } else if(root1) {                                  // Both are not Null
            return (root1->val == root2->val) && ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
                                                 (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
        } else {
            return true;                                    // Both are Null
        }
    }
};