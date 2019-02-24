/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        // binary tree
        // time complexity: O(n), space complexity: O(1)
        // main idea:
        // Traverse binary tree levelly, and keep the most left node and prev node
        // When start at next level, set cur to recorded most left node in next level
        
        // #prev# used to store the last node in current traverse in this level
        // #head# used to store the first node in this level
        Node *prev = nullptr, *head = nullptr, *cur = root;
        while(cur) {
            while(cur) {
                if(cur->left) {
                    if(prev) prev->next = cur->left;                // connect
                    else head = cur->left;                          // keep head node
                    prev = cur->left;                              
                } 
                if(cur->right) {
                    if(prev) prev->next = cur->right;               // connect
                    else head = cur->right;                         // keep head node
                    prev = cur->right;
                }
                cur = cur->next;
            }
            cur = head;                                             // switch to the next level's first node
            prev = head = nullptr;
        }
        return root;
    }
};