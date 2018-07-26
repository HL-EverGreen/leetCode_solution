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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {//String all pearls with one needle
        ListNode* newList=new ListNode(0);
        ListNode* res=newList;
        while(l1&&l2){
            if(l1->val<=l2->val){
                newList->next=l1;
                l1=l1->next;
            }
            else{
                newList->next=l2;
                l2=l2->next;
            }
            newList=newList->next;
        }
        newList->next=l1?l1:l2;
        return res->next;
    }
};