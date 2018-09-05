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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { //linked list
        if(!headA || !headB) return nullptr;
        ListNode *p1=headA, *p2=headB;
        while(p1 && p2 && p1!=p2){
            p1=p1->next;
            p2=p2->next;
            if(p1==p2) return p1;
            if(!p1) p1=headB;   //when one pointer come at the end of one linked list, change to another
            if(!p2) p2=headA;   //so that when they both come to collision node, the distance is same (or no intersection they come the NULL at the same time)
        }
        return p1;
    }
};