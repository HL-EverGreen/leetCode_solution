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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //because we need to find the inorder successor, which means find the least element that bigger than p->val
        //so when root->val<=p, update root=root->right; when root->val>p, save the root->val,
        //and update root=root->left to find if there is smaller element still bigger than p->val
        if(!root || !p) return nullptr;
        TreeNode* succ=nullptr;
        int target=p->val;
        while(root){
            if(root->val<=target){
                root=root->right;
            }else{
                succ=root;
                root=root->left;
            }
        }
        return succ;
    }
};