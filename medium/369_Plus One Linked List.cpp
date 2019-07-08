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
    ListNode* plusOne(ListNode* head) {
        // linked list & recursive
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 0ms, beats 100%
        
        // Here I use add K instead of add 1 to increase extensibility
        // Use recursive method. Each one return current carry to add.
        if(!head) return nullptr;
        if(addOne(head, 1)) {                           // If still has carry (1)
            ListNode* new_head = new ListNode(1);
            new_head->next = head;
            head = new_head;
        }
        return head;
    }
    
    // Return current carry to add
    int addOne(ListNode* head, int K) {
        if(head->next) {
            K = addOne(head->next, K);
        }
        int cur = head->val + K;
        head->val = cur % 10;
        return cur / 10;
    }
};