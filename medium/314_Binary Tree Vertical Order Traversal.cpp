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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // binary tree & BFS
        // time complexity: normal traverse time, space complexity: O(n)
        // 8ms, beats 100%
        
        // main idea:
        // 1. Use map (ordered) to store all col elements grouped by col index
        // 2. Push all these elements into result
        
        vector<vector<int>> res;
        if(!root) return res;
        
        map<int, vector<int>> treeCol;
        queue<pair<int, TreeNode*>> node;
        node.push({0, root});
        
        while(!node.empty()) {
            int col = node.front().first;
            TreeNode* cur = node.front().second;
            node.pop();
            treeCol[col].push_back(cur->val);
            if(cur->left) node.push({col - 1, cur->left});
            if(cur->right) node.push({col + 1, cur->right});
        }
        
        for(auto col : treeCol)
            res.push_back(col.second);
        return res;
    }
};