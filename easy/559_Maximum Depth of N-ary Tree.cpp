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
    int maxDepth(Node* root) {
        // N-tree & DFS & BFS
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 144ms, beats 90.13%
        
        // Main idea:
        // Straight forward.
        if(!root) { return 0; }
        int depth = 0;
        for(auto child : root->children) { depth = max(depth, maxDepth(child)); }
        return depth + 1;
        
        
        // Method 2:
        // BFS
        /*
        if(!root) { return 0; }
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        
        while(!q.empty()) {
            depth++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                Node* cur = q.front();
                q.pop();
                for(auto child : cur->children) {
                    q.push(child);
                }
            }
        } 
        return depth;
        */
    }
};