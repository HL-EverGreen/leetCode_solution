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
vector<int> inorderTraversal(TreeNode* root) {
        // binary tree

        // method 2: 
        // inorder traversal using stack
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 100%
        /*
        vector<int> res;
        if(!root) return res;
        
        stack<TreeNode*> node;
        while(true) {
            while(root) {
                node.push(root);
                root = root->left;
            }
            if(node.empty()) break;
            root = node.top();
            node.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
        */
        
        // method 3:
        // morris traversal, without using stack
        // time complexity: O(n), space complexity: O(1)

        // 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
        // 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
        //   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
        //   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
        // 3. 重复以上1、2直到当前节点为空。
        
        vector<int> res;
        if(!root) return res;
        
        TreeNode* cur = root, *prev = nullptr;
        while(cur) {
            if(cur->left == nullptr) {              // 1.
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                prev = cur->left;
                while(prev->right != nullptr && prev->right != cur) prev = prev->right;         // find the predecessor
                if(prev->right == nullptr) {        // 2.a
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = nullptr;          // 2.b
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }

    // method 1: recursion
    /*
    vector<int> inorderTraversal(TreeNode* root) {
        // binary tree
        // time complexity: O(n), space complexity: O(n) (recursion stack)
        // 0ms, beats 100%
        
        vector<int> res;
        inorderTraversal(root, res);
        return res;
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& res) {
        if(root) {
            inorderTraversal(root->left, res);
            res.push_back(root->val);
            inorderTraversal(root->right, res);
        }
    }
    */
};