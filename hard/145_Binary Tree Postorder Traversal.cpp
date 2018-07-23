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
    vector<int> postorderTraversal(TreeNode* root) {//iterative
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        TreeNode* last=nullptr;
        
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                cur=cur->left;
            }
            else{
                TreeNode* top=s.top();
                if(top->right && last!=top->right){
                    cur=top->right;
                }
                else{
                    res.push_back(top->val);
                    last=top;
                    s.pop();
                }
            }
        }
        return res;
        
    }
    
};