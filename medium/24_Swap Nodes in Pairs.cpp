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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur=head;
        ListNode* tmp=head;
        ListNode* final_head=head;
        ListNode* prev=new ListNode(0);
        prev->next=head;
        if(cur&&cur->next)
            final_head=cur->next;
        while(cur&&cur->next){//be careful about the usage of "next", reduce the "next" as much as possible. e.g. line 24 
            tmp=cur->next->next;
            prev->next=cur->next;
            prev->next->next=cur;
            cur->next=tmp;
            prev=cur;         //instead of prev=prev->next->next;
            cur=cur->next;
        }
        return final_head;
        
    }
};