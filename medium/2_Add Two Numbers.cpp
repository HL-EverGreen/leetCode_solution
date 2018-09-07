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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {//linked_list
        ListNode *dummy=new ListNode(0), *p=dummy;
        int car=0, cur=0;
        while(l1 || l2 || car){
            cur=(l1?l1->val:0)+(l2?l2->val:0)+car;
            car=cur/10;
            cur%=10;
            ListNode* new_node=new ListNode(cur);
            p->next=new_node;
            p=p->next;
            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        return dummy->next;
        
        //same idea but too prolix
        /*
        ListNode* dummy=new ListNode(0), *p=dummy;
        int car=0, cur=0;
        if(!l1) return l2;
        if(!l2) return l1;
        while(l1&&l2){
            cur=l1->val+l2->val+car;
            car=cur/10;
            cur%=10;
            ListNode* new_node=new ListNode(cur);
            p->next=new_node;
            p=p->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            while(l1){
                cur=l1->val+car;
                car=cur/10;
                cur%=10;
                ListNode* new_node=new ListNode(cur);
                p->next=new_node;
                p=p->next;
                l1=l1->next;
            }
        }
        else if(l2){
            while(l2){
                cur=l2->val+car;
                car=cur/10;
                cur%=10;
                ListNode* new_node=new ListNode(cur);
                p->next=new_node;
                p=p->next;
                l2=l2->next;
            }
        }
        if(car)
            p->next=new ListNode(1);
        return dummy->next;
        */
    }
};