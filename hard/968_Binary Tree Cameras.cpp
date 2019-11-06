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
    int minCameraCover(TreeNode* root) {
        // greedy & DFS
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 8ms, beats 93.42%
        
        // Main idea:
        // Greedy allocate camera. for each leaf node, no need to allocate camera.
        // We use different return value to present current node's status
        // There are three return value:
        //   1) return 0: current node is covered (or null) without a camera
        //   2) return 1: current node is not covered
        //   3) return 2: current node is covered and with a camera on its position
        // So, if either of two child return 1, the current node must be placed a camera.
        // If both the child return 0, then current node isn't be covered, so must return 1.
        // Else if one of the child return 2, then the current node is covered as well, return 0
        
        int res = 0;
        if(calMinCamera(root, res) == 1) ++res;     // Handle edge case: the root hasn't been covered yet
        return res;
    }
    
    int calMinCamera(TreeNode* root, int& res) {
        if(!root) return 0;
        int left = calMinCamera(root->left, res);
        int right = calMinCamera(root->right, res);
        if(!left && !right) return 1;   // Leaf node or has child node but already be covered, and current node isn't covered
        if(left == 1 || right == 1) {   // One of the child not covered, must place camera
            ++res;
            return 2;
        }
        return 0;
    }
};