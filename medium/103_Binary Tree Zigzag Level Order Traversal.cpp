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
    // binary tree & BFS
    // 12ms, beats 100%

    // method 1
    // traditional preorder traversal method + reverse alternatively
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        traverseTree(res, root, 0);
        for(int i = 1; i < res.size(); i += 2) reverse(res[i].begin(), res[i].end());
        return res;
    }
    
    void traverseTree(vector<vector<int>>& res, TreeNode *root, int depth) {
        if(root == nullptr) return;
        if(depth == res.size()) res.push_back({});
        res[depth].push_back(root->val);
        traverseTree(res, root->left, depth + 1);
        traverseTree(res, root->right, depth + 1);
    }

    // method 2
    // BFS + reverse flag, can be more faster (doesn't need to reverse every two line)
    /*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        // 12ms, beats 100%
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        TreeNode* tmp;
        bool dir = true;                       //save direction
        q.push(root);
        while(!q.empty()){
            int size = q.size(), index;
            vector<int> row(size);
            for(int i = 0; i < size; i++){
                tmp = q.front();
                q.pop();
                if(dir) index = i;             //left to right
                else index = size - i - 1;     //right to left
                row[index] = tmp->val;
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            dir = !dir;
            res.push_back(row);
        }
        return res;
    }
    */
};