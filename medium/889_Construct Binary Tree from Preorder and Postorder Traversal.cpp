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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        // Binary tree & stack
        // time complexity: O(n), space complexity: O(n)
        // 8ms, beats 90.76%
        
        // Main idea:
        // Use stack to store current tree path.
        // And when the top element == post[j], it means that node(post[j]) has completed its construction, could pop out.
        vector<TreeNode*> stk;
        stk.push_back(new TreeNode(pre[0]));
        for(int i = 1, j = 0; i < pre.size(); i++) {
            TreeNode* cur = new TreeNode(pre[i]);           // Current node
            while(stk.back()->val == post[j]) {             // stk.back() has compelted its construction
                stk.pop_back();
                j++;
            }
            if(stk.back()->left == nullptr) {
                stk.back()->left = cur;
            } else {
                stk.back()->right = cur;
            }
            stk.push_back(cur);
        }
        return stk[0];
    }
};