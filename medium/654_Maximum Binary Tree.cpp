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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // Binary tree & Stack
        // time complexity: O(n), space complexity: O(n)
        // 64ms, beats 98.71%
        
        // Main idea:
        // Use stack to maintain decreasing array, and update stack continually
        // The tree root is always the most bottom node
        vector<TreeNode*> stk;
        int num = nums.size();
        
        for(int i = 0; i < num; i++) {
            TreeNode* cur = new TreeNode(nums[i]);
            
            /* Newly added node is the bigger than current top node's value */
            while(!stk.empty() && stk.back()->val < cur->val) {
                cur->left = stk.back();
                stk.pop_back();
            }
            
            /* Update right child */
            if(!stk.empty() && stk.back()->val > cur->val) {
                stk.back()->right = cur;
            }
            stk.push_back(cur);
        }
        return stk.front();
    }
};