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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        // binary tree & graph
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 94.18%
        
        // Main idea:
        // Traverse the tree first to construct the mapping from child to parent.
        // So that we can do DFS start from target node.
        
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<int> visited; 
        vector<int> res;
        
        // Build mapping relationship from child to parent
        findParent(root, parent);
        // Do dfs and find nodes at distance K with target
        dfs(res, parent, visited, target, K);
        return res;
    }
    
    // Build mapping from child to parent
    void findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        if(!root) return;
        if(root->left) {
            parent[root->left] = root;
            findParent(root->left, parent);
        }
        if(root->right) {
            parent[root->right] = root;
            findParent(root->right, parent);
        }
    }
    
    // Do DFS and search nodes whose distance with target is K
    void dfs(vector<int>& res, unordered_map<TreeNode*, TreeNode*>& parent,
             unordered_set<int>& visited, TreeNode* cur, int K) {
        if(cur == nullptr || visited.count(cur->val)) return;
        if(K == 0) {    // Find node with distance K
            res.push_back(cur->val);
            return;
        }
        
        visited.insert(cur->val);
        if(parent.count(cur)) dfs(res, parent, visited, parent[cur], K - 1);
        dfs(res, parent, visited, cur->left, K - 1);
        dfs(res, parent, visited, cur->right, K - 1);
    }
};