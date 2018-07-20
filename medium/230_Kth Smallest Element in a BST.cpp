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
    int kthSmallest(TreeNode* root, int k) {//sort all value first
        vector<int> value;
        gatherValue(value,root);
        sort(value.begin(),value.end());
        return value[k-1];
    }
    
    void gatherValue(vector<int>& value, TreeNode* head){
        if(head){
            value.push_back(head->val);
            gatherValue(value,head->left);
            gatherValue(value,head->right);
        }
    }
};