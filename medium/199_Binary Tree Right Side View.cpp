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
        // binary tree

        // method 1: modified traversal
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 4ms, beats 100%
        
        // main idea:
        // traverse order: root->right->left, only select first countered node in its depth to be added into res
        
        vector<int> res;
        rightSideView(root, res, 1);
        return res;
    }
    
    void rightSideView(TreeNode* root, vector<int>& res, int depth) {
        if(!root) return;
        if(depth > res.size()) res.push_back(root->val);
        rightSideView(root->right, res, depth + 1);
        rightSideView(root->left, res, depth + 1);
    }


    // method 2
    // level order traverse and push last one in each level
    // time complexity: O(n), space complexity: O(n) + stack memory
    /*
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
    */
};