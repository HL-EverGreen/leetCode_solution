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
    bool isCousins(TreeNode* root, int x, int y) {
        // binary tree & BFS
        // time complexity: O(n), space complexity: O(n)
        // 0ms, beats 100%
        
        // Main idea:
        // Use BFS do level traversal, in each level: 
        //   1) If both the nodes are found, compare their parent.
        //   2) If only one node is found, return false.
        // *Besides pure nodes, also push node's parent node into the queue. queue<pair<Node, Parent>>

        queue<pair<TreeNode*, TreeNode*>> q;    // pair: Node, Node's parent
        q.push({root, nullptr});
        
        while(!q.empty()) {
            bool isAExist = false;
            bool isBExist = false;
            TreeNode* aPar = nullptr;
            TreeNode* bPar = nullptr;
            int n = q.size();
            
            for(int i = 0; i < n; ++i) {
                auto curPair = q.front();
                q.pop();
                
                TreeNode* curNode = curPair.first;
                if(curNode->val == x) {
                    isAExist = true;
                    aPar = curPair.second;
                } else if(curNode->val == y) {
                    isBExist = true;
                    bPar = curPair.second;
                }
                
                if(isAExist && isBExist) return aPar != bPar;           // Both nodes are found in the same level
                if(curNode->left) q.push({curNode->left, curNode});
                if(curNode->right) q.push({curNode->right, curNode});
            }
            if(isAExist || isBExist) return false;                      // Only one node is found, return false
        }
        return false;
    }
};