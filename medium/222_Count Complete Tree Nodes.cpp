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
    int height(TreeNode* root){
        if(!root) return -1;
        return 1+height(root->left);
    }
    
    int countNodes(TreeNode* root) { //complete tree property
        if(!root) return 0;
        int h=height(root), res=0;
        while(h>=0){
            if(height(root->right) == h-1){ //说明左子树满
                res+= 1<<h;
                root=root->right;
            }
            else{                           //说明右子树最后一层全空
                res+=1<<(h-1);
                root = root->left;
            }
            h--;
        }
        return res;
        
        // too slow, recursive
        /*
        if(!root) return 0;
        int cl=0,cr=0;
        TreeNode* lr=root, *rr=root;
        while(lr){ cl++; lr=lr->left;} 
        while(rr){ cr++;rr=rr->right;}
        if(cl==cr) return pow(2,cl)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
        */
    }
};