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
    ListNode* deleteDuplicates(ListNode* head) {//linked_list
        if(!head) return nullptr;
        if(!head->next) return head;
        
        int val=head->val;
        ListNode* nex=head->next;
        if(nex->val!=val){
            head->next=deleteDuplicates(nex);
            return head;
        }else{
            while(nex&&nex->val==val) nex=nex->next;
            return deleteDuplicates(nex);
        }
    }
};