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
    Node* connect(Node* root) {
        // binary tree
        // time complexity: O(n), space complexity: O(1)
        // 68ms, beats 33%

        // constant space || iteration
        // main idea:
        // 1. cur is the most left node in each layer
        // 2. if cur && cur->left, begin connect cur->left layer
        // 3. update cur until cur->left == nullptr (connect all layers)
        if(!root) return nullptr;
        Node* cur = root;
        while(cur->left) {
            Node* tmp = cur;                        // cur层遍历
            while(tmp) {
                tmp->left->next = tmp->right;
                if(tmp->next) tmp->right->next = tmp->next->left;
                tmp = tmp->next;
            }
            cur = cur->left;
        }
        return root;

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