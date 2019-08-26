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
    // dfs
    // best time complexity: O(nlogn) for balanced tree.
    // worst time complexity: O(n^2) for unbalanced tree
    // space complexity: O(1)
    /*
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return pathSum(root->left, sum) + pathSum(root->right, sum) + pathSumFrom(root, sum);
    }
    
    int pathSumFrom(TreeNode* root, int sum) {
        if(!root) return 0;
        int cur = 0;
        if(sum == root->val) cur = 1;
        return cur + pathSumFrom(root->left, sum - root->val) + pathSumFrom(root->right, sum - root->val);
    }
    */
    
    // prefix sum, kind of DP
    // time complexity: O(n), space complexity: O(n) + recursion stack memory
    // 16ms, beats 90.20%
    
    // main idea:
    // For each node, record all prefix sum along the predecessor nodes.
    // If current sum is `cur`, we just need to calculate count of `cur - sum`.
    // Because if there is a path whose sum is `cur`, and a path whose sum is `cur - sum`,
    // then the difference path of them is the one we are finding
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> sumCnt;
        sumCnt[0] = 1;
        return findPath(root, sumCnt, sum, 0);
    }
    
    /* Use hash table to record current path's count of prefix sum */
    int findPath(TreeNode* root, unordered_map<int, int>& sumCnt, int sum, int cur) {
        if(!root) return 0;
        int res = 0;
        cur += root->val;
        res += sumCnt[cur - sum];
        sumCnt[cur]++;
        res += findPath(root->left, sumCnt, sum, cur) + findPath(root->right, sumCnt, sum, cur);
        sumCnt[cur]--;          // Remove count of prefix sum which in another branch.
        return res;
    }
};