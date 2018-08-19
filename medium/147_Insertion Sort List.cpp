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
    ListNode* insertionSortList(ListNode* head) {
        //modify the original list
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=dummy,*cur=head;
        while(cur){
            if(cur->next && cur->next->val<cur->val){
                while(prev->next && prev->next->val<cur->next->val) prev=prev->next;
                ListNode* tmp=prev->next;
                prev->next=cur->next;
                cur->next=cur->next->next;
                prev->next->next=tmp;
                prev=dummy;
            }
            else cur=cur->next;
        }
        return dummy->next;
        
        //create a new list and add listnode to the new list
        /*
        ListNode *new_list=new ListNode(0),*cur,*tmp,*prev;
        while(head){
            cur=head;      
            tmp=head->next;
            cur->next=NULL;
            head=tmp;                 //remove element in old linked list
            if(new_list->next==NULL){
                new_list->next=cur;
                continue;
            }
            tmp=new_list->next;
            prev=new_list;
            while(tmp){
                if(tmp->val>cur->val){
                    cur->next=tmp;
                    prev->next=cur;
                    break;
                }else{
                    prev=prev->next;
                    tmp=tmp->next;
                }
            }
            if(!tmp){
                cur->next=tmp;
                prev->next=cur;
            }
        }
        return new_list->next;
        */
    }
};