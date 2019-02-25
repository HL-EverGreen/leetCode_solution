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
    int rob(TreeNode* root) {
        // binary tree
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 20ms, beats 100%
        
        // main idea:
        // compare sum of this node's value + grandchild nodes' value and sum of child nodes' value
        int l, r;
        return tryRob(root, l, r);
    }
    
    int tryRob(TreeNode* root, int& l, int& r) {
        if(!root) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};