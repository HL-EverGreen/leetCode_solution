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
    // Method 1:
    // Recursive, top down
    // Time complexity: O(nlogn), space complexity: O(logn) of stack memory
    ListNode* sortList(ListNode* head) { //sort linked list, time complexity: O(nlogn)
        if(!head || !head->next) return head;
        ListNode* slow=head, *fast=head->next;
        while(fast && fast->next){ //find middle node
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* headb=slow->next; //headb: head of the 2nd half of linked list
        slow->next=NULL;
        return merge(sortList(head), sortList(headb));
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2){ //merge two linked list into one ordered list
        ListNode* new_head=new ListNode(0), *tmp=new_head;
        while(head1 || head2){
            if(head1 && (!head2 || head1->val<=head2->val)){
                tmp->next=head1;
                tmp=tmp->next;
                head1=head1->next;
            }
            if(head2 && (!head1 || head2->val<head1->val)){
                tmp->next=head2;
                tmp=tmp->next;
                head2=head2->next;
            }
        }
        tmp->next=NULL;
        return new_head->next;
    }
};

// Method 2
// Iteration, bottom up
// time complexity: O(nlogn), space complexity: O(1)
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(!head || !(head->next)) return head;
        
        //get the linked list's length
        ListNode* cur = head;
        int length = 0;
        while(cur){
            length++;
            cur = cur->next;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for(int step = 1; step < length; step <<= 1){
            cur = dummy.next;
            tail = &dummy;
            while(cur){
                left = cur;
                right = split(left, step);
                cur = split(right,step);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }
private:
    /**
     * Divide the linked list into two lists,
     * while the first list contains first n ndoes
     * return the second list's head
     */
    ListNode* split(ListNode *head, int n){
        //if(!head) return NULL;
        for(int i = 1; head && i < n; i++) head = head->next;
        
        if(!head) return NULL;
        ListNode *second = head->next;
        head->next = NULL;
        return second;
    }
    /**
      * merge the two sorted linked list l1 and l2,
      * then append the merged sorted linked list to the node head
      * return the tail of the merged sorted linked list
     */
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head){
        ListNode *cur = head;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while(cur->next) cur = cur->next;
        return cur;
    }
};
