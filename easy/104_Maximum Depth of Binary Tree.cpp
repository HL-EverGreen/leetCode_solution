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
    int maxDepth(TreeNode* root) {
        // binary tree
        // time complexity: normal traverse time, space complexity: O(1) + stack memory
        // 20ms, beats 98.76%
        
        // recursive, kind of DFS?
        if(!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
        
        
        // BFS
        /*
        if(root == NULL) return 0;
        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            ++ res;
            for(int i = 0, n = q.size(); i < n; ++ i) {
                TreeNode *p = q.front();
                q.pop();
                if(p -> left != NULL) q.push(p -> left);
                if(p -> right != NULL) q.push(p -> right);
            }
        }
        return res;
        */
    }
    
    
    // method 2
    // Time complexity: O(n)
    // 4ms, beats 98.89%
    // Top down 2
    /*
    int maxDepth(TreeNode* root) {
        int max_depth = 0, cur_depth = 0;
        curMaxDepth(root, max_depth, cur_depth);
        return max_depth;
    }
    
    void curMaxDepth(TreeNode* root, int& max_depth, int cur_depth) {
        if(root != nullptr) {
            cur_depth++;
            max_depth = max(max_depth, cur_depth);
            curMaxDepth(root->left, max_depth, cur_depth);
            curMaxDepth(root->right, max_depth, cur_depth);
        }
    }
    */
};