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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // BST
        // time complexity: O(n), space complexity: O(1)
        // 40ms, beats 99.25%
        
        // main idea:
        // Find succ is the same as find the least element greater than p->val
        // So when root->val <= p->val, set root to root->right
        // When root->val > p->val, set succ = root, then root = root->left
        if(!root || !p) return nullptr;
        TreeNode* succ = nullptr;
        while(root) {
            if(root->val <= p->val) root = root->right;
            else {
                succ = root;
                root = root->left;
            }
        }
        return succ;
    }
};