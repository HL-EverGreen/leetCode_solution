/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // linked list to BST
        // time complexity: O(nlogn), space complexity: O(1) + stack memory
        // 40ms, beats 100%
        
        // follow up: use array to store value in lists first can reduce time complexity to O(n) : 
        // 1) O(n) to convert to array
        // 2) O(logn) to generate BST, since only need O(1) to find the middle node
        
        return sortedListToBST(head, nullptr);
    }
    
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if(head == tail) return nullptr;
        if(head->next == tail) return new TreeNode(head->val);              // directly return #new TreeNode(head->val)# instead the following 
                                                                            // to save running time
        
        ListNode* fast = head, *mid = head;
        while(fast != tail && fast->next != tail) {                         // find the middle node
            fast = fast->next->next;
            mid = mid->next;
        }
        
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(mid->next, tail);
        return root;
    }
};