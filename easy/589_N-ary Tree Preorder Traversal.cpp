/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        // N-tree & recursive & iterative & stack
        // time complexity: O(n), space complexity: O(n)
        // 148ms, beats 95.73%
        
        // Main idea:
        // Recursive is trivial.
        // Iterative: each time push all child nodes to the stack from right to left.
        // So that when access they will be read in preorder order.
        if(!root) { return {}; }
        stack<Node*> stk;
        vector<int> res;
        stk.push(root);
        while(!stk.empty()) {
            Node* tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            
            /* Push all child node to the stack */
            for(int i = tmp->children.size() - 1; i >= 0; i--) {
                if(tmp->children[i]) {
                    stk.push(tmp->children[i]);
                }
            }
        }
        return res;
    }
};