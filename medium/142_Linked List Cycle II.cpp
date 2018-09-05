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
    ListNode *detectCycle(ListNode *head) { //find circle entry in linked list
        //L1 is defined as the distance between the head point and entry point
        //L2 is defined as the distance between the entry point and the meeting point
        //C is defined as the length of the cycle
        //n is defined as the travel times of the fast pointer around the cycle When the first encounter of the slow pointer and the fast pointer
        //According to the definition of L1, L2 and C, we can obtain:
        //the total distance of the slow pointer traveled when encounter is L1 + L2
        //the total distance of the fast pointer traveled when encounter is L1 + L2 + n * C
        //Because the total distance the fast pointer traveled is twice as the slow pointer, Thus:
        //2 * (L1+L2) = L1 + L2 + n * C => L1 + L2 = n * C => L1 = (n - 1) C + (C - L2)*
        //It can be concluded that the distance between the head location and entry location is equal to the 
        //distance between the meeting location and the entry location along the direction of forward movement.
        ListNode *fast=head, *slow=head;
        if(!head || !head->next) return nullptr;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                slow=head;
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};