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
    TreeNode* recoverFromPreorder(string S) {
        // Stack & Binary Tree
        // time complexity: O(n), space complexity: O(n)
        // 16ms, beats 99.48%
        
        // Main idea:
        // Use a stack to record current node in each depth
        // When stack.size() > depth, pop element until find node with corresponding depth
        // Which means, each layer can only has one node in stack at the same time
        int size = S.length();
        vector<TreeNode*> tree;
        
        /* Handle byte by byte */
        for(int idx = 0, depth, num; idx < size;) {
            /* Count dash number */
            for(depth = 0; idx < S.length() && S[idx] == '-'; idx++) {
                depth++;
            }
            /* Calculate number */
            for(num = 0; idx < S.length() && S[idx] != '-'; idx++) {
                num = num * 10 + (S[idx] - '0');
            }
            
            /* Insert new node */
            TreeNode *cur = new TreeNode(num);
            while(tree.size() > depth) { tree.pop_back(); }
            if(!tree.empty()) {
                if(!tree.back()->left) { tree.back()->left = cur; }
                else { tree.back()->right = cur; }
            }
            tree.push_back(cur);
        }
        return tree[0];

    }
    
    
    /*** Not use following function because context swtich require lots of time ***/
    /* Count number of adjacent dashes */
    int countDash(string S, int& index) {
        int cnt = 0;
        while(index < S.length() && S[index] == '-') {
            cnt++;
            index++;
        }
        return cnt;
    }
    
    /* Calculate next number */
    int countNumber(string S, int& index) {
        int num = 0;
        while(index < S.length() && S[index] != '-') {
            num = num * 10 + (S[index] - '0');
            index++;
        }
        return num;
    }
};