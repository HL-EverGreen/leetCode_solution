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
    vector<int> postorder(Node* root) {
        // N-tree & iterative & stack & recursive
        // time complexity: O(n), space complexity: O(n)
        // 148ms, beats 95.63%
        
        // Main idea:
        // Same as 589, since require postorder, we can simply add all child from left to right, and reverse the final result and return.
        if(!root) { return {}; }
        vector<int> res;
        stack<Node*> stk;
        stk.push(root);
        while(!stk.empty()) {
            Node* tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            for(int i = 0; i < tmp->children.size(); i++) {         // Push child from left to right
                if(tmp->children[i]) {
                    stk.push(tmp->children[i]);
                }
            }
        }
        
        /* Reverse the result! */
        reverse(res.begin(), res.end());
        return res;
    }
};