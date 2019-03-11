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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // binary tree
        // time complexity: O(n) - normal traverse time, space complexity: O(1) + stack memory
        // 20ms, beats 100%
        
        // main idea:
        // Based on inorder traverse, use lb and rb to represent whether current is located on left bound or right bound
        // Add order: left bound - leafs - right bound
        
        if(!root) return {};
        vector<int> res;
        res.push_back(root->val);
        getBounds(root->left, res, true, false);
        getBounds(root->right, res, false, true);
        return res;
    }
    
    void getBounds(TreeNode* root, vector<int>& res, bool lb, bool rb) {
        if(!root) return;
        if(lb) res.push_back(root->val);                                                    // add left bound
        if(!lb && !rb && !root->left && !root->right) res.push_back(root->val);             // add leafs
        getBounds(root->left, res, lb, rb & !root->right);
        getBounds(root->right, res, lb & !root->left, rb);
        if(rb) res.push_back(root->val);                                                    // add right bound
    }
};