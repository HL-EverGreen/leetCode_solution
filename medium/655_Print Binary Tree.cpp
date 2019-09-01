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
    vector<vector<string>> printTree(TreeNode* root) {
        // binary tree & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 0ms, beats 100%
        
        // Main idea:
        // Get the height and the width of tree first, and then do DFS on tree.
        // On each recursion, put current node's value into the middle position of current range.
        int h = getHeight(root);
        int w = getWidth(root);
        vector<vector<string>> res(h, vector<string>(w));
        dfs(res, root, 0, 0, w - 1);
        return res;
    }
private:
    /* Calcualte the height of the tree*/
    int getHeight(TreeNode* p) {
        if(!p) return 0;
        return max(getHeight(p->left), getHeight(p->right)) + 1;
    }
    
    /* Calculate the width of the tree */
    int getWidth(TreeNode* p) {
        if(!p) return 0;
        return max(getWidth(p->left), getWidth(p->right)) * 2 + 1;
    }
    
    /* Populate the result */
    void dfs(vector<vector<string>>& res, TreeNode* p, int level, int l, int r) {
        if(!p) return;
        
        // Always put the value in the middle of the range.
        int mid = l + (r - l) / 2;
        res[level][mid] = to_string(p->val);
        
        dfs(res, p->left, level + 1, l, mid-1);
        dfs(res, p->right, level + 1, mid+1, r);
    }
};