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
    ListNode* reverseKGroup(ListNode* head, int k) {//linked_list
        if(!head || k<=1) return head;
        int num=0;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *cur=dummy, *nex, *prev=dummy;
        while(cur=cur->next) num++;
        while(num>=k){
            cur=prev->next;
            nex=cur->next;
            for(int i=1;i<k;i++){
                cur->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=cur->next;
            }
            prev=cur;
            num-=k;
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