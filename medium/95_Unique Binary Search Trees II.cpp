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
    vector<TreeNode*> generateTrees(int n) {//dp
        if(n==0) return vector<TreeNode*>();
        vector<TreeNode*> res(1,nullptr);
        for(int i=1;i<=n;i++){
            vector<TreeNode*> tmp; //each round use all old trees in #res# to generate new tree and store in #tmp#, then res=tmp
            for(int j=0;j<res.size();j++){
                TreeNode* old_root=res[j]; 
                TreeNode* new_root=new TreeNode(i);
                TreeNode* cl_old_root=clone(old_root);
                new_root->left=cl_old_root;
                tmp.push_back(new_root); //use new node as root
                
                if(old_root){
                    TreeNode* tmp_old=old_root;
                    while(tmp_old->right){ 
                        TreeNode* new_root1=new TreeNode(i); //insert new node in the old tree(not use as root)
                        TreeNode* tmp_right=tmp_old->right;
                        
                        tmp_old->right=new_root1;  //insert at every (root->right) position and move the original right subtree to left subtree of the new node
                        new_root1->left=tmp_right;
                        TreeNode* cl_old_root=clone(old_root);
                        tmp.push_back(cl_old_root);
                        
                        tmp_old->right=tmp_right; //recover the tree
                        tmp_old=tmp_old->right;
                    }
                    tmp_old->right=new TreeNode(i); //insert the new node at the rightest position
                    TreeNode* cl_old_root=clone(old_root);
                    tmp.push_back(cl_old_root);
                    tmp_old->right=nullptr;
                }
            }
            res=tmp; //update #res# after each round
        }
        return res;
    }
    
    TreeNode* clone(TreeNode* root){ //return the same tree with new root which has a different pointer address
        if(!root) return nullptr;
        TreeNode* new_root=new TreeNode(root->val);
        new_root->left=clone(root->left);
        new_root->right=clone(root->right);
        return new_root;
    }
};