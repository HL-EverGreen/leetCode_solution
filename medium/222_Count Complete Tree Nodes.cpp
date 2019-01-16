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
    int countNodes(TreeNode* root) { //complete tree property
        // binary tree
        // time complexity: O(log(n)^2), log(n) ~ tree's height, space complexity: O(1)
        // 16ms, beats 99.34%
        
        // compare root->right's height with h - 1
        // if == h - 1, then left subtree is full
        // if != h - 1, then right subtree's last layer is empty
        int h = height(root), res = 0;
        while(h >= 0) {
            if(height(root->right) == h - 1) {  // left subtree is full
                res += 1<<h;
                root = root->right;
            } else {                            // right subtree's last layer is empty
                res += 1<<(h - 1);
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

    int height(TreeNode* root) {
        if(!root) { return -1; }
        return 1 + height(root->left);
    }
};