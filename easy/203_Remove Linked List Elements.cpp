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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=dummy, *cur=head;
        while(cur){
            if(cur->val==val){
                prev->next=cur->next; //considering memory leak, maybe we should delete useless nodes after changing the linked list
                cur=cur->next;
            }else{
                cur=cur->next;
                prev=prev->next;
            }
        }
        return dummy->next;
    }
};