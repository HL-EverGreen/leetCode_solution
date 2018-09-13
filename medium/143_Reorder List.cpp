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
    void reorderList(ListNode* head) { //linked list
        ListNode* slow=head, *fast=head;
        if(head){
            while(fast && fast->next){
                slow=slow->next;
                fast=fast->next->next;
            }
            fast=slow->next; 
            slow->next=nullptr;   //find mid node and divide list into two parts
            slow=fast;
            if(slow){
                ListNode* tmp=slow->next;
                slow->next=nullptr;
                while(tmp){      //reverse the second part
                    fast=tmp;
                    tmp=fast->next;
                    fast->next=slow;
                    slow=fast;
                }
                ListNode *dummy=new ListNode(0);
                tmp=dummy;
                while(fast && head){   //merge two parts
                    tmp->next=head;
                    head=head->next;
                    tmp=tmp->next;
                    tmp->next=fast;
                    fast=fast->next;
                    tmp=tmp->next;
                }
                if(head) tmp->next=head;
                head=dummy->next;
            }    
        }
    }
};