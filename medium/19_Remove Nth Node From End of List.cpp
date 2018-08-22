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
    ListNode* removeNthFromEnd(ListNode* head, int n) {//linked_list
        ListNode **l1=&head, *l2=head;
        for(int i=1;i<n;i++){ //set l2 in ahead of l1 within n-1 steps, so when l2 reaches end, l1 reaches the Nth node from end of list
            if(l2->next) l2=l2->next;
            else return head;
        }
        while(l2->next){
            l2=l2->next;
            l1=&((*l1)->next);
        }
        *l1=(*l1)->next;
        return head;
    }
};