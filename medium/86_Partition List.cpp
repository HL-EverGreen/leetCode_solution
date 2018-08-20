/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {//linked list
        ListNode* s_list=new ListNode(0);
        ListNode* b_list=new ListNode(0);
        ListNode *s_cur=s_list, *b_cur=b_list;
        //or can write
        /*
        ListNode s_list(0),b_list(0);
        ListNode *s_cur=&s_list, *b_cur=&b_list;
        */
        while(head){
            if(head->val<x){
                s_cur->next=head;
                s_cur=s_cur->next;
            }else{
                b_cur->next=head;
                b_cur=b_cur->next;
            }
            head=head->next;
        }
        s_cur->next=b_list->next;
        b_cur->next=NULL;
        return s_list->next;
    }
};