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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }
    
    TreeNode* buildTree(vector<int>& nums, int left, int right){ //recursive
        if(left>right) return nullptr;
        int mid=(left+right)/2;
        TreeNode* newNode=new TreeNode(nums[mid]);
        newNode->left=buildTree(nums,left,mid-1);
        newNode->right=buildTree(nums,mid+1,right);
        return newNode;
    }
};