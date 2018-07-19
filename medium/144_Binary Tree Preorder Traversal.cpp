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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        /*
        if(root){
            res.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return res;
        */
        
        //use iteration instead of recursion
        stack<TreeNode*> s;
        if(!root) 
            return res;
        s.push(root);
        TreeNode* temp_p;
        while(!s.empty()){
            temp_p=s.top();
            res.push_back(temp_p->val);
            s.pop();
            if(temp_p->right)
                s.push(temp_p->right);
            if(temp_p->left)
                s.push(temp_p->left);
        }
        return res;
    }
};