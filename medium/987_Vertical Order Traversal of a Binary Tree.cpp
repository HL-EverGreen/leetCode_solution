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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // binary tree
        // time complexity: O(nlogn), space complexity: O(n)
        // 4ms, beats 91.90%
        
        // Main idea:
        // Directly traverse the binary tree and record each node's value in map<int, map<int, set<int>>>.
        // Since all elements is ordered, simply loop and get the result.
        
        map<int, map<int, set<int>>> m;
        vector<vector<int>> res;
        traverse(root, m, 0, 0);    // Record the node's position and its value
        for(auto& x : m) {
            res.push_back(vector<int>());
            for(auto& y : x.second) {
                res.back().insert(res.back().end(), y.second.begin(), y.second.end());
            }
        }
        return res;
    }
    
    // Preorder traversal and record node's value paired with its coordination
    void traverse(TreeNode* root, map<int, map<int, set<int>>>& m, int x, int y) {
        if(!root) return;
        m[x][y].insert(root->val);
        traverse(root->left, m, x - 1, y + 1);
        traverse(root->right, m, x + 1, y + 1);
    }
};