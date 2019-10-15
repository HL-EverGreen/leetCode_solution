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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // linked list
        // time complexity: O(n), space complexity: O(1)
        // 52ms, beats 98.07%
        
        // main idea:
        // When p1 reach at end of A, set p1 = B's head. Same as p2
        // So if exists interesction, the total distance would be same and p1 p2 will reach the intersection simultaneously.
        // If doesn't exist, p1 and p2 will reach NULL simultaneously
        if(!headA || !headB) return nullptr;
        ListNode *p1 = headA, *p2 = headB;
        while(p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if(p1 == p2) return p1;
            if(!p1) p1 = headB;
            if(!p2) p2 = headA;
        }
        return p1;

        // More concise version
        ListNode* curA = headA, *curB = headB;
        while(curA != curB) {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        return curA;
    }
};