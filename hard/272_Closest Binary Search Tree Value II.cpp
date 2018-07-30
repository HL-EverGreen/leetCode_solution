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
    vector<int> closestKValues(TreeNode* root, double target, int k) {//priority_queue
        priority_queue<pair<double,int>> pq;
        //priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq; //小顶堆
        vector<int> res;
        preOrderTraversal(root,pq,target,k);
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void preOrderTraversal(TreeNode* root, priority_queue<pair<double,int>>& pq, double target, int k){
        if(!root) return;
        pq.push(make_pair(fabs(root->val-target), root->val));
        if(pq.size()>k) pq.pop();
        preOrderTraversal(root->left,pq,target,k);
        preOrderTraversal(root->right,pq,target,k);
    }
};