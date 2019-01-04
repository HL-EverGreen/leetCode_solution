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
    // method 1
    // recursive
    // 8ms, beats 100%
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0) { return {}; }
        return generateTrees(1, n);
    }
    
    vector<TreeNode*> generateTrees(int left, int right) {
        if(left > right) { return {nullptr}; }
        else if(left == right) {
            TreeNode* tmp = new TreeNode(left);
            return {tmp};
        }
        vector<TreeNode*> result;
        for(int i = left; i <= right; i++) {
            vector<TreeNode*> left_sub = generateTrees(left, i - 1);
            vector<TreeNode*> right_sub = generateTrees(i + 1, right);
            for(auto l_sub : left_sub) {
                for(auto r_sub : right_sub) {
                    TreeNode* root = new TreeNode(i);
                    root -> left = l_sub;
                    root -> right = r_sub;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    
    
    
    // method 2
    // dynamic programming
    // 8ms, beats 100%
    /*
    vector<TreeNode*> generateTrees(int n) {        
        if(n == 0) { return vector<TreeNode*>(); }
        vector<TreeNode*> res(1, nullptr);
        
        for(int i = 1; i <= n; i++) {
            vector<TreeNode*> cur;                                       // each round use all old trees in $res$ to generate new tree and store in $cur$, then res = cur
            for(int j = 0; j < res.size(); j++) {
                TreeNode* new_root = new TreeNode(i);                    // insert new node as a root 
                TreeNode* old_root = cloneTree(res[j]);
                new_root -> left = old_root;
                cur.push_back(new_root);
                
                if(res[j] != nullptr) {
                    TreeNode* cur_root = old_root;
                    while(cur_root -> right != nullptr) {               // insert at every (root->right) position and move the original right subtree to left subtree of the new node
                        TreeNode* temp_right_tree = cur_root -> right;
                        new_root = new TreeNode(i);
                        
                        cur_root -> right = new_root;
                        new_root -> left = temp_right_tree;
                        TreeNode* cl_old_root = cloneTree(old_root);
                        cur.push_back(cl_old_root);
                        
                        cur_root -> right = temp_right_tree;            // recover past tree in result
                        cur_root = cur_root -> right;
                    }
                    cur_root -> right = new TreeNode(i);                // insert the new node at the rightest position
                    TreeNode* cl_old_root = cloneTree(old_root);
                    cur.push_back(cl_old_root);
                    cur_root -> right = nullptr;                        // recover past tree in result
                }
            }
            res = cur;
        }
        return res;
    }
    
    TreeNode* cloneTree(TreeNode* root) {                   // deep copy, return the same tree with new root which has a different pointer address
        if(!root) { return nullptr; }
        TreeNode* new_root = new TreeNode(root -> val);
        new_root -> left = cloneTree(root -> left);
        new_root -> right = cloneTree(root -> right);
        return new_root;
    }
    */
};