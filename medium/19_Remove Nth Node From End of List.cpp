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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Linked_list
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 91.64%
        // Use dummy head version
        ListNode *dummy = new ListNode(0), *prev = dummy, *second = dummy;
        dummy->next = head;
        while(n--) {
            second = second->next;
        }
        while(second->next) {
            prev = prev->next;
            second = second->next;
        }
        prev->next = prev->next->next;
        return dummy->next;

        // Use ** version, 取地址做法相当于dummy
        /*
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
        */
    }
};