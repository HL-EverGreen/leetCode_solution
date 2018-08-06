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
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        preorderTraversal(root,q);
        if(root){
            TreeNode* prev=q.front();
            q.pop();
            while(!q.empty()){ //reconnect each node into linked list 
                TreeNode* cur=q.front();
                q.pop();
                prev->right=cur;
                prev->left=NULL;
                prev=cur;
            }    
        }
    }
    
    void preorderTraversal(TreeNode* root, queue<TreeNode*>& q){//push all node preorderly in queue
        if(root){
            q.push(root);
            preorderTraversal(root->left,q);
            preorderTraversal(root->right,q);
        }
    }
};