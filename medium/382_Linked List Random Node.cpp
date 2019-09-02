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
    // math & reservoir sampling
    // time complexity: O(n), space complexity: O(1)
    // 32ms, beats 96.51%
    
    // Main idea:
    // proof:
    // 1) For n = 1, n = 2, the answer is obvious.
    // 2) Suppose for n = i, the probabity of ith node being picked is 1/i, and when add one node,
    //    the probabity of ith node being picked is (1/i) * (1-1/(1+i)) = 1/(i+1), still correct.
    //    (ith node is picked only when ith node is picked (1/i) and (i+1)th node isn't picked (1-1/(i+1)))
    
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        list = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res, len = 1;
        ListNode* node = list;
        
        while(node) {
            if(rand() % len == 0) res = node->val;          // 1/len probabity to be updated
            ++len;
            node = node->next;
        }
        return res;
    }
private:
    ListNode* list;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */