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
    bool isSymmetric(TreeNode* root) {//iteration using queue
        if(!root)
            return true;
        TreeNode* p_l=root->left;
        TreeNode* p_r=root->right;
        queue<TreeNode*> q1,q2;
        q1.push(p_l);
        q2.push(p_r);
        while(!q1.empty()&&!q2.empty()){
            p_l=q1.front();
            p_r=q2.front();
            if(p_l&&p_r){
                if(p_l->val!=p_r->val)
                    return false;
                q1.push(p_l->right); 
                q1.push(p_l->left);
                q2.push(p_r->left);
                q2.push(p_r->right);
            }
            else if(p_l||p_r)
                return false;
            q1.pop();
            q2.pop();
        }
        return true;
    }
};