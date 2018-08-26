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
    ListNode* reverseBetween(ListNode* head, int m, int n) {//linked_list
        ListNode* dummy=new ListNode(0), *prev=dummy, *cur=head, *nex;
        dummy->next=head;
        for(int i=0;i<m-1;i++) prev=prev->next; //since the question denotes that 1 ≤ m ≤ n ≤ length of list, so we didn't need #while# to determine if #prev# is NULL, and simply using iteration is enough
        cur=prev->next;
        for(int i=m-1;i<n-1;i++){ //reverse nodes
            nex=cur->next;
            cur->next=nex->next;
            nex->next=prev->next;
            prev->next=nex;
        }
        return dummy->next;
    }
};