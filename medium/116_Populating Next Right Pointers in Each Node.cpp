/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        //constant space || iterative
        if(!root) return;
        while(root->left){
            TreeLinkNode* tmp=root;
            while(tmp) {
                tmp->left->next=tmp->right;
                if(tmp->next) tmp->right->next=tmp->next->left;
                tmp=tmp->next;
            }
            root=root->left;
        }

        //constant space || recursive
        /*
        if (!root) return;
        if (root -> left) {
            root -> left -> next = root -> right;
            if (root -> next)
                root -> right -> next = root -> next -> left;
        }
        connect(root -> left);
        connect(root -> right);
        */
        
        //use queue, not constant extra space
        /*
        queue<TreeLinkNode*> q;
        if(root) q.push(root);
        while(!q.empty()){
            int size=q.size();
            TreeLinkNode* prev=q.front();
            TreeLinkNode* cur;
            if(prev->left){
                q.push(prev->left);
                q.push(prev->right);
            }
            q.pop();
            for(int i=0;i<size-1;i++){
                cur=q.front();
                if(cur->left){
                    q.push(cur->left);
                    q.push(cur->right);
                }
                q.pop();
                prev->next=cur;
                prev=cur;
            }
            prev->next=NULL;
        }
        */
    }
};