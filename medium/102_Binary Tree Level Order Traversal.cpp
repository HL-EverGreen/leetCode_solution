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
    
};