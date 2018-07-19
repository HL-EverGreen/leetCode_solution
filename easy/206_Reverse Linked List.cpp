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
    ListNode* reverseList(ListNode* head) {
        /*
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
        */
        
        //use pointer exchange
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};