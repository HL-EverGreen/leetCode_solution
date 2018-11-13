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
    ListNode* rotateRight(ListNode* head, int k) { 
        //list
        //time complexity: O(n)

        //if less than one node
        if(!head || head -> next == NULL) return head;
        int len = 1;
        ListNode* temp = head;
        while(temp -> next){
            temp = temp -> next;
            len++;
        }
        
        //connect tail and head to construct a circle
        temp -> next = head;
        
        //construct new list
        if(k %= len){
            for(int count = 0; count < len - k; count++){
                temp = temp -> next;
            }
        }
        head = temp -> next;
        temp -> next = NULL;
        return head;
    }
};