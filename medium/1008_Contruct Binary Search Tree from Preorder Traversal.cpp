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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Stack & BST
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // Main idea:
        // Use decreasing stack to record BST's structure.
        // Use dummy head to record head node.
        stack<TreeNode*> stk;
        TreeNode dummy(INT_MAX);
        stk.push(&dummy);
        
        for(auto num : preorder) {
            TreeNode *cur = new TreeNode(num), *tmp = nullptr;
            
            /* Add left child */
            if(!stk.empty() && stk.top()->val > cur->val) {
                stk.top()->left = cur;
            }
            
            /* Add right child */
            while(!stk.empty() && stk.top()->val < cur->val) {
                tmp = stk.top();
                stk.pop();
            }
            if(tmp) {
                tmp->right = cur;
            }
            
            /* Push current node */
            stk.push(cur);
        }
        return dummy.left;
    }
};