class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
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
        stack<int> stk;
        int lower_bound=INT_MIN;
        for(int i=0;i<preorder.size();i++){
            if(stk.empty() || preorder[i]<stk.top()){//use stk.top() instead preorder[i-1] can save time. stk.top() always = preorder[i-1]
                if(preorder[i]<lower_bound) return false;
                stk.push(preorder[i]);
            }else{
                while(!stk.empty() && preorder[i]>stk.top()){
                    lower_bound=stk.top();
                    stk.pop();
                }
                stk.push(preorder[i]);
            }
        }
        return true;
    }
};