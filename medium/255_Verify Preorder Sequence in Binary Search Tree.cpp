class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        // BST
        // time complexity: O(n), space complexity: O(n)
        // 36ms, beats 100%
        
        // main idea: 
        // maintain the lower_bound value
        // when we find an element greater than its former elements, we can set the new lower_bound, and a normal BST won't appear any emelent less than that in the following array
        
        /*
        To translate this into code: looking for the trend of numbers, if it’s decreasing, it’s still traversing the left child node 
        all the way down, we push the value into stack. When we read a value greater than the last one, we know the current value 
        belongs to a right node (let it be rc: right child) of one of the previous nodes (let it be p) we pushed to stack, 
        in other words, p is a parent node of the current node rc. Due to the property of preorder traversal, p’s value is 
        pushed to stack before its left subtree nodes, so to find the parent node, we pop all the nodes in its left subtree, 
        and the last popped node whose value is smaller than rc is rc’s parent p, whose value becomes the lower bound. 
        Then we keep reading the serialized array, in any case we see any value not greater than the lower bound, we return false. 
        Lower bound is updated whenever we read a right child node’s value.
        */
        
        stack<int> node;
        int lower_bound = INT_MIN, size = preorder.size();
        for(int i = 0; i < size; i++) {
            if(node.empty() || preorder[i] < node.top()) {              // still go into the left subtree
                if(preorder[i] < lower_bound) return false;             
            } else {
                while(!node.empty() && preorder[i] > node.top()) {
                    lower_bound = node.top();                           // go into the right side, won't less than the top() value
                    node.pop();
                }
            }
            node.push(preorder[i]);
        }
        return true;
    }
};