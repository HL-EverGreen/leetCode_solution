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
    TreeNode* f_node, *s_node, *prev_node=new TreeNode(INT_MIN);

    void recoverTree(TreeNode* root) { //BST
        inorderTraverse(root);
        swap(f_node->val,s_node->val);
    }
    
    void inorderTraverse(TreeNode* root){
        if(!root) return;
        inorderTraverse(root->left);
        if(!f_node && prev_node->val>root->val) f_node=prev_node;
        if(f_node && prev_node->val>root->val) s_node=root; //如果前序遍历向量中两相邻值交换，则第一次就找到了f_node和s_node
                                                            //如果非相邻两值交换，则第一次找到值后继续迭代，继续找到第二个异常值后更新s_node
        prev_node=root; //update the prev node
        inorderTraverse(root->right);
    }
};