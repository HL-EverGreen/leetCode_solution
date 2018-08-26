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
    ListNode* sortList(ListNode* head) { //sort linked list, time complexity: O(nlogn)
        if(!head || !head->next) return head;
        ListNode* slow=head, *fast=head->next;
        while(fast && fast->next){ //find middle node
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* headb=slow->next; //headb: head of the 2nd half of linked list
        slow->next=NULL;
        return merge(sortList(head), sortList(headb));
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2){ //merge two linked list into one ordered list
        ListNode* new_head=new ListNode(0), *tmp=new_head;
        while(head1 || head2){
            if(head1 && (!head2 || head1->val<=head2->val)){
                tmp->next=head1;
                tmp=tmp->next;
                head1=head1->next;
            }
            if(head2 && (!head1 || head2->val<head1->val)){
                tmp->next=head2;
                tmp=tmp->next;
                head2=head2->next;
            }
        }
        tmp->next=NULL;
        return new_head->next;
    }
};