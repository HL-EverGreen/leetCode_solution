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
    bool isPalindrome(ListNode* head) {//linked_list
        //save element in vector first, O(n) Time and O(n) Space
        //if want to reduce the space usage, we could find the middle node and reverse the right half part of the list, then compare two half, O(n) Time & O(1) Space
        vector<int> list_elem;
        int size=0;
        while(head){
            list_elem.push_back(head->val);
            size++;
            head=head->next;
        }
        for(int i=0;i<(size+1)/2;i++)
            if(list_elem[i]!=list_elem[size-i-1]) return false;
        return true;
    }
};