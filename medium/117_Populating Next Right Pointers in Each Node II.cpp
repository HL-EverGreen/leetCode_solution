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
    void connect(TreeLinkNode *root) {  //binary tree
        //main idea is to traverse binary tree levelly
        TreeLinkNode *prev=NULL, *head=NULL, *cur=root; //#prev# used to store the last node in this level
                                                        //#head# used to store the first node in this level
        while(cur){
            while(cur){
                if(cur->left){
                    if(prev) prev->next=cur->left;
                    else head=cur->left;
                    prev=cur->left;
                }
                if(cur->right){
                    if(prev) prev->next=cur->right;
                    else head=cur->right;
                    prev=cur->right;
                }
                cur=cur->next;
            }
            cur=head; //switch to the next level
            prev=head=NULL;
        }
    }
};