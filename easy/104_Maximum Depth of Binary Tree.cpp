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
    int res=0;
    int finalres=0;
    int maxDepth(TreeNode* root) {
        if(root){
            res++;
            if(res>finalres)
                finalres=res;
            int temp=res;
            maxDepth(root->left);
            res=temp;
            maxDepth(root->right);
            res=temp-1;
        }
        return finalres;
    }
};