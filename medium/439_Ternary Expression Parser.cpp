class Solution {
public:
    string parseTernary(string expression) {
        // string & subclause
        // time complexity: O(n), space complexity: O(1) + stack memory
        // 12ms, beats 66.67%
        
        // main idea:
        // Like basic calculator recursion, process each entire block
        // Process entire block by dividing into many small blocks and process each
        // After processing each block, i's position +2 can access next block
        int i = 0;
        return parseTernary(expression, i);
    }
    
    // notice the int&, after each clause being processed, i will at pos of last value. So need to +2 to access next subclause
    string parseTernary(string& expression, int& i) {
        if(i < expression.size() - 1 && expression[i + 1] == '?') {     // if a subclause
            int i0 = i;
            i += 2;
            string a = parseTernary(expression, i);
            i += 2;
            string b = parseTernary(expression, i);
            return expression[i0] == 'T' ? a : b;
        }
        return expression.substr(i, 1);                                 // if a single value
    }
};

// Ternary expression to binary tree
// Using stack
/*
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x): val(x), left(nullptr), right(nullptr){}       // constructor
};
 
TreeNode* ternaryToBT(string input) {
    TreeNode* root = new TreeNode(input[0]);
    tmp = root;
    stack<TreeNode*> mystack;
    for (int i = 1; i < input.length(); i += 2) {
        if (input[i] == '?') {
            tmp->left = new TreeNode(input[i+1]);
            mystack.push(tmp);
            tmp = tmp->left;
        }
        else if (input[i] == ':') {
            tmp = mystack.top();
            mystack.pop();
            tmp->right = new TreeNode(input[i+1]);
            tmp = tmp->right;
        }
    }
    return root;
}
*/