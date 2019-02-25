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
    TreeNode* convertBST(TreeNode* root) {
        // binary search tree
        // time complexity: O(n), space complexity: O(1)
        // 44ms, beats 100%
        
        // main idea:
        // 1. Utilize BST's property, traverse right subtree and add all nodes' value in right subtree
        // 2. then add this to current node's value
        // 3. Traverse left subtree
        
        int acc = 0;
        buildGreaterTree(root, acc);
        return root;
    }
    
    void buildGreaterTree(TreeNode* root, int& acc) {
        if(!root) return;
        buildGreaterTree(root->right, acc);
        acc += root->val;
        root->val = acc;
        buildGreaterTree(root->left, acc);
    }
};