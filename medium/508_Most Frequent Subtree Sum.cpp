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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // dfs
        // time complexity: O(n), space complexity: O(n) + stack memory
        // 20ms, beats 87.34%

        // Do DFS to record all sum and find the largest frequency
        // And iterate hash table to find res
        unordered_map<int, int> m;
        int max_cnt = 0;
        calSum(root, m, max_cnt);

        vector<int> res;
        for(auto iter : m) {
            if(iter.second == max_cnt){ res.push_back(iter.first); }
        }
        return res;
    }

    int calSum(TreeNode* root, unordered_map<int, int>& m, int& max_cnt) {
        if(root == nullptr) { return 0; }
        int val = root->val + calSum(root->left, m, max_cnt) + calSum(root->right, m, max_cnt);
        max_cnt = max(max_cnt, ++m[val]);
        return val;
    }
};
