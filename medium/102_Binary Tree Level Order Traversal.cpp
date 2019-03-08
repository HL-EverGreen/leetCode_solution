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
    // binary tree

    // method 1:
    // DFS
    // 8ms, beats 100%
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        readTree(root,0);
        return res;
    }
    
    void readTree(TreeNode* root, int depth){
        if(root){
            if(depth==res.size())
                res.push_back(vector<int>());
            res[depth].push_back(root->val);
            readTree(root->left,depth+1);
            readTree(root->right,depth+1);
        }
    }


    // method 2:
    // BFS
    // 8ms, beats 100%
    /*
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(!root) return res;
        q.push(root);
        while(!q.empty()) {
            res.push_back(vector<int>());
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto cur = q.front();
                q.pop();
                res.back().push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return res;
    }
    */
    
};