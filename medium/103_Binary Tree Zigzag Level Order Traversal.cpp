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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){ // queue
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        TreeNode* tmp;
        bool dir=true;  //save direction
        q.push(root);
        while(!q.empty()){
            int size=q.size(),index;
            vector<int> row(size);
            for(int i=0;i<size;i++){
                tmp=q.front();
                q.pop();
                if(dir) index=i;        //left to right
                else index=size-i-1;    //right to left
                row[index]=tmp->val;
                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);
            }
            dir=!dir;
            res.push_back(row);
        }
        return res;
    }
    
    //traditional preorder traversal method + reverse alternatively
    /*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        preorderTraversal(root,res,0);
        for(int i=0;i<res.size();i++)
            if(i%2==1)
                reverse(res[i].begin(),res[i].end());
        return res;
    }
    
    void preorderTraversal(TreeNode* root, vector<vector<int>>& res, int depth){
        if(root){
            if(res.size()==depth)
                res.push_back(vector<int>());
            res[depth].push_back(root->val);
            preorderTraversal(root->left,res,depth+1);
            preorderTraversal(root->right,res,depth+1);
        }
    }
    */
};