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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // linked list
        // time complexity: O(n), space complexity: O(1)
        // 20ms, beats 92.23%
        
        // Main idea:
        // First add two linked list according to 位(一个node可能出现val是十几的情况), reverse store the list.
        // Loop through the list to adjust based on carry, reverse the result.
        
        int n1 = 0, n2 = 0, carry = 0;
        ListNode *curr1 = l1, *curr2 = l2, *res = NULL;
        /* Count number of nodes */
        while(curr1){ curr1 = curr1->next; n1++; }
        while(curr2){ curr2 = curr2->next; n2++; } 
        curr1 = l1; curr2 = l2;
        /* Add according to 位, and reverselt generate the result */
        while(n1 > 0 && n2 > 0){
            int sum = 0;
            if(n1 >= n2){ sum += curr1->val; curr1=curr1->next; n1--;}
            if(n2 > n1){ sum += curr2->val; curr2=curr2->next; n2--;}
            res = addToFront(sum, res);
        }
        /* Modify linked list according to carry, reversely generate result */
        curr1 = res; res = NULL;
        while(curr1){
            curr1->val += carry; carry = curr1->val / 10;
            res = addToFront(curr1->val % 10, res);
            curr2 = curr1; 
            curr1 = curr1->next;
            delete curr2;
        }
        if(carry) res = addToFront(1, res );
        return res;
    }
    
    ListNode* addToFront(int val, ListNode* head){
        ListNode* temp = new ListNode(val);
        temp->next = head;
        return temp;
    }
};