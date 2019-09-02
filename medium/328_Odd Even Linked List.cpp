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
    ListNode* oddEvenList(ListNode* head) {
        // Linked list
        // time complexity: O(n), space complexity: O(1)
        // 16ms, beats 71.13%
        
        // Main idea:
        // Use odd and even head to connect odd and even nodes, and then connect odd list to even list's head
        
        if(!head) return nullptr;
        ListNode *odd = head, *evenHead = head->next, *even = evenHead;
        while(even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;       // Connect even list after odd list
        return head;
    }
};