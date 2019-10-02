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
    bool findTarget(TreeNode* root, int k) {
        // BST
        // time complexity: O(n), space complexity: O(n)
        // 36ms, beats 88.44%
        
        // Main idea:
        // Iterative preorder traversal
        
        if(!root) return false;
        unordered_set<int> db;
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty()) {
            auto node = s.top(); s.pop();
            int cur = node->val;
            if(db.count(k - cur)) return true;  // Find pair
            db.insert(cur);
            if(node->right) s.push(node->right);
            if(node->left) s.push(node->left);
        }
        return false;
    }
};