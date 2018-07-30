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
    ListNode* deleteDuplicates(ListNode* head) {//list_iteration
        ListNode* list_head=head;
        if(head){
            while(head->next){
                if(head->next->val==head->val)
                    head->next=head->next->next;
                else head=head->next;
            }
        }
        return list_head;
    }
};