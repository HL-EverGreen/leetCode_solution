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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        // BST
        // time complxity: O(kST), 0 < k < 1, space complexity: O(n)
        // 24ms, beats 90.92%
        
        // Main idea:
        // The brute force is to compare each subtree in `s` with `t`. So O(ST) time.
        // This method first calculate `t`'s depth, and only compare nodes with equal
        // depth in `s` with `t`.

        // ***NOTICE: Also can serialize tree into string and determine whether s1
        // contains s2. AND can use serialization + KMP to achieve O(S+T) time!

        vector<TreeNode*> cands;
        findDepthAndNodes(s, cands, findDepth(t));  // Gather candidates
        
        for(auto& cand : cands) {   // Validate candidates
            if(isSame(cand, t)) return true;
        }
        return false;
    }
private:
    /* Determine whether two trees are the same */
    bool isSame(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t || s->val != t->val) return false;
        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
    
    /* Calculate the depth of given tree */
    int findDepth(TreeNode* t) {
        if(!t) return -1;
        return 1 + max(findDepth(t->left), findDepth(t->right));
    }
    
    /* Push nodes with given depth in given tree into vector */
    int findDepthAndNodes(TreeNode* t, vector<TreeNode*>& nodes, int d) {
        if(!t) return -1;
        int depth = 1 + max(findDepthAndNodes(t->left, nodes, d), 
                            findDepthAndNodes(t->right, nodes, d));
        if(depth == d) nodes.push_back(t);
        return depth;
    }
};