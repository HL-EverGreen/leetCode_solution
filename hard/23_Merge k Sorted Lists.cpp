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
    // list & priority queue
    // time complexity: O(nlogn), n is the total number of nodes, space complexity: O(k), k is the number of list
    // 20ms, beats 99.1%
    
    // method 1: using priority queue
    struct compare{
        bool operator() (const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, compare> nextNode;
        
        // push head node for each list
        int numList = lists.size();
        for(int i = 0; i < numList; i++) {
            if(lists[i] != nullptr) {
                nextNode.push(lists[i]);
            }
        }
        
        // update the priority queue
        ListNode* dummy = new ListNode(0), *cur = dummy;
        while(!nextNode.empty()) {
            ListNode* next = nextNode.top();
            nextNode.pop();
            cur->next = next;                    // Connect `cur` with `next` piece
            if(!nextNode.empty()) {
                int gap = nextNode.top()->val;                              // Smallest value in another list
                while(next->next != nullptr && next->next->val < gap) {     // Skip all value which smaller than `gap`
                    next = next->next;
                }
            }
            cur = next;                                                     // Set current tail
            if(next->next != nullptr) nextNode.push(next->next);            // If still has unconnected list, push to `pq`
        }
        return dummy->next;
    }
    
    /*
    // method 2: divided into many merge two lists problems
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // even works well when NULL exists in #lists# without evidently determine if there is NULL
        if(lists.empty()) return nullptr;
        while(lists.size() > 1) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        
        // iteration version
        ListNode* newHead = new ListNode(0), *cur = newHead;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1) cur->next = l1;
        else cur->next = l2;
        return newHead->next;
        
        // recursive version
        // if(l1->val < l2->val) {
        //     l1->next = mergeTwoLists(l1->next, l2);
        //     return l1;
        // } else {
        //     l2->next = mergeTwoLists(l1, l2->next);
        //     return l2;
        // }
    }
    */
};