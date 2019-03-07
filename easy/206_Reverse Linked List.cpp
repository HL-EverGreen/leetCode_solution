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
    // linked list
    
    // iterative
    // 8ms, beats 100%
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *cur = head, *next;
        while(cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    
    // recursive
    // 16ms, beats 13.06%
    /*
    ListNode* reverseList(ListNode* head) {
        return reverseList(head, nullptr);
    }
    
    ListNode* reverseList(ListNode* cur, ListNode* prev) {
        if(!cur) return prev;
        ListNode* next = cur->next;
        cur->next = prev;
        return reverseList(next, cur);
    }
    */

    // first step :)
    /*
    ListNode* reverseList(ListNode* head) {
        vector<int> temp;
        ListNode* temphead=head;
        ListNode* reshead=head;
        if(head==NULL) return head;
        temp.push_back(head->val);
        while(head->next!=NULL){
            head=head->next;
            temp.push_back(head->val);
        }
        int i=0;
        while(temphead!=NULL){
            temphead->val=temp[temp.size()-1-i];
            temphead=temphead->next;
            i++;
        }
        return reshead;
    }
    */
};