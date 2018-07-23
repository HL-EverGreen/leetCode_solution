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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> value;
        vector<int> res;
        readTree(value, root, 0);
        for(int i=0;i<value.size();i++){
            res.push_back(value[i][value[i].size()-1]);
        }
        return res;
    }
    
    void readTree(vector<vector<int>>& value, TreeNode* root, int depth){//read tree per level
        if(root){
            if(value.size()==depth)
                value.push_back(vector<int>());
            value[depth].push_back(root->val);    
            readTree(value, root->left, depth+1);
            readTree(value, root->right, depth+1);
        }
    }
};