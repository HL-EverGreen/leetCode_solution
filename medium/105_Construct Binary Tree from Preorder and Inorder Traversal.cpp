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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // array & binary search tree
        // time complexity: O(n)
        // 8ms, beats 97.48%
        
        // tree        8 4 5 3 7 3
        // preorder    8 [4 3 3 7] [5]
        // inorder     [3 3 4 7] 8 [5]

        // 每次从 preorder 头部取一个值 mid，作为树的根节点
        // 检查 mid 在 inorder 中 的位置，则 mid 前面部分将作为 树的左子树，右部分作为树的右子树
        return buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* buildTree(vector<int>& preorder, int root_index, int p_end, vector<int>& inorder, int i_start, int i_end) {
        if(root_index >= p_end || i_start >= i_end) {
            return NULL;
        }
        
        // current tree's root value
        int mid = preorder[root_index];
        auto pos = find(inorder.begin() + i_start, inorder.begin() + i_end, mid);
        int dis = pos - inorder.begin() - i_start;
        
        TreeNode* root = new TreeNode(mid);
        root->left = buildTree(preorder, root_index + 1, root_index + dis + 1, inorder, i_start, i_start + dis);
        root->right = buildTree(preorder, root_index + dis + 1, p_end, inorder, i_start + dis + 1, i_end);
        return root;
    }
};