/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct bound {
    int cnt;
    int mi;
    int ma;
    bound(int c, int left, int right):cnt(c), mi(left), ma(right) {};
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        // binary tree
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 98.44%
        
        // Main idea:
        // Use struct bound to record each node's status:
        // <max size of BST tree, min value in subtree, max value in subtree>
        // So we can determine if left subtree, right subtree and current node can
        // continually consist a BST
        
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    // Postorder traversal to get the max size of BST
    bound dfs(TreeNode* root, int& res) {
        if(!root) return bound(0, INT_MAX, INT_MIN);    // Null
        bound b(-1, 0, 0);
        
        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        
        // Can't consist BST including current root
        if(left.cnt == -1 || right.cnt == -1
          || root->val >= right.mi || root->val <= left.ma) return b;
        
        // Can consist BST, adjust range and count and return
        b.cnt = left.cnt + right.cnt + 1;
        b.mi = min(root->val, left.mi);
        b.ma = max(root->val, right.ma);
        res = max(res, b.cnt);
        return b;
    }
};