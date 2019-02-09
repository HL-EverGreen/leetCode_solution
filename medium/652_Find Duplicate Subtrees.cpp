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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // tree & pattern
        // 64ms, beats 100%
        
        // Main idea: 
        // 1. Store all subtrees' pattern in a hash table
        // 2. Find those duplicated pattern
        unordered_map<string, vector<TreeNode*>> pattern;
        vector<TreeNode*> dups;
        serializeTree(root, pattern);
        for(auto iter : pattern) {
            if(iter.second.size() > 1) dups.push_back(iter.second.front());
        }
        return dups;
    }
    
    // construct and store all subtrees' pattern in a hash table
    string serializeTree(TreeNode* root, unordered_map<string, vector<TreeNode*>>& pattern) {
        if(root == nullptr) return "";
        string patt = "(" + serializeTree(root->left, pattern) + to_string(root->val) + serializeTree(root->right, pattern) + ")";
        pattern[patt].push_back(root);
        return patt;
    }
};