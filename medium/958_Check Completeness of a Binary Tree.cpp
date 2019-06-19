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
    bool isCompleteTree(TreeNode* root) {
        // BFS
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 95.2%
        
        // Main idea:
        // Use bfs to push node or node's child (including null).
        // Keep traverse until encounter nullptr.
        // Start from first nullptr and continue searching in vector,
        // until out of index of encounter non-nullptr.
        // If encounter non-nullptr, i != vector.size().
        if(!root) { return true; }
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        int i = 0;
        /* Push node in BFS order */
        while(i < bfs.size() && bfs[i]) {
            bfs.push_back(bfs[i]->left);
            bfs.push_back(bfs[i]->right);
            i++;
        }
        
        /* Continue checking whether exist non-nullptr */
        while(i < bfs.size() && !bfs[i]) {
            i++;
        }
        
        return i == bfs.size();
    }
};