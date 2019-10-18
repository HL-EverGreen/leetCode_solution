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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // linked list
        // time complexity: O(n), space complexity: O(1)
        // 20ms, beats 70.19%
        
        // Main idea:
        // Cal total number first, if remain number >= K, then can still reverse K.
        // The reverse process is:
        //     1) Find cur based on prev
        //     2) Set node sequencely
        //     3) Keep cur and prev not move in current round, only move next
        //     4) When finishs current round, set prev to cur.
        
        ListNode* dummy = new ListNode(0), *prev = dummy, *next = nullptr;
        ListNode* cur = head;
        prev->next = head;
        int N = 0;
        
        // Compute number of all nodes
        while(cur) {
            ++N; cur = cur->next;
        }
        
        while(N >= k) {
            cur = prev->next;
            for(int i = 1; i < k; ++i) {    // Each reverse k
                next = cur->next;
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
            } 
            prev = cur;
            N -= k;
        }
        return dummy->next;
    }
    
    //recursive solution
    /*
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *p=head, *q=head;
        
        for(int i=0;i<k;i++){
            if(!p) return head;
            p=p->next;
        }
        
        ListNode* newHead=reverseList(q, p);
        q->next=reverseKGroup(p, k);
        
        return newHead;
    }
    
    ListNode* reverseList(ListNode *head, ListNode *tail){
        ListNode *prev=nullptr, *cur=head, *next;
        
        while(cur!=tail){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        return prev;
    }
    */
};