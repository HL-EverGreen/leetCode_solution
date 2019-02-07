/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // list
        // time complexity: O(n), space complexity: O(n)
        // 60ms, beats 10%, using hashmap can be faster
        
        // first expand original list by adding same node after each node
        // then separate the list into two new same list
        // return the new list
        
        RandomListNode *newHead, *l1, *l2;
        if(!head) return nullptr;
        
        // expand original list by adding same node after each node
        for(l1 = head; l1 != nullptr; l1 = l1->next->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }
        
        newHead = head->next;
        
        // set random pointer
        for(l1 = head; l1 != nullptr; l1 = l1->next->next) {
            if(l1->random != nullptr) l1->next->random = l1->random->next;
        }
        
        // seperate list
        for(l1 = head; l1 != nullptr; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if(l2->next != nullptr) l2->next = l2->next->next;
        }
        return newHead;
    }
};