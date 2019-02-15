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
    int minDepth(TreeNode* root) {//binary tree
        // BFS & binary tree
        // time complexity: O(n), space complexity: O(n)
        // 20ms, beats 100%
        
        int res = 0;
        queue<TreeNode*> q;
        if(!root) return 0;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            res++;
            for(int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(!(cur->left) && !(cur->right)) return res;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return res;


        // recursive method
        /*
        int min_depth=INT_MAX;
        findMinimumDepth(root,min_depth,0);
        if(!root) return 0;
        return min_depth;
        */

        //a consice solution
        /*
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
        */
    }

    /*
    void findMinimumDepth(TreeNode* root, int& min_depth, int depth){
        if(root){
            depth++;
            if(root->left) findMinimumDepth(root->left,min_depth,depth);
            if(root->right) findMinimumDepth(root->right,min_depth,depth);
            else if(!root->left) min_depth=min(min_depth,depth);
        }
    }
    */
};