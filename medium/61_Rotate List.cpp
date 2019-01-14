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
    ListNode* rotateRight(ListNode* head, int k) {
        // list & two pointers
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 99.71%
        
        // if less than one node
        if(!head || head -> next == NULL) { return head; }
        int len = 1;
        ListNode* cur = head;
        while(cur -> next) {
            len++;
            cur = cur -> next;
        }
        
        // connect tail and head to construct a circle
        cur -> next = head;
        
        // construct new list
        if(k %= len) {
            for(int i = 0; i < len - k; i++) {
                cur = cur -> next;    
            }
        }
        head = cur -> next;
        cur -> next = NULL;
        return head;
    }
};