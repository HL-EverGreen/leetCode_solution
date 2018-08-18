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
    /* from Preorder and Inorder Traversal */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    
    }

    TreeNode* helper(vector<int>& preorder,int root_index,int pend,vector<int>& inorder,int istart,int iend)
    {
        // tree        8 4 5 3 7 3
        // preorder    8 [4 3 3 7] [5]
        // inorder     [3 3 4 7] 8 [5]

        // 每次从 preorder 头部取一个值 mid，作为树的根节点
        // 检查 mid 在 inorder 中 的位置，则 mid 前面部分将作为 树的左子树，右部分作为树的右子树

        if(root_index >= pend || istart >= pend)
            return NULL;

        int mid = preorder[root_index];
        auto f = find(inorder.begin() + istart,inorder.begin() + iend,mid);

        int dis = f - inorder.begin() - istart;

        TreeNode* root = new TreeNode(mid);
        root -> left = helper(preorder,root_index + 1,root_index + 1 + dis,inorder,istart,istart + dis);
        root -> right = helper(preorder,root_index + 1 + dis,pend,inorder,istart + dis + 1,iend);
        return root;
    }
};