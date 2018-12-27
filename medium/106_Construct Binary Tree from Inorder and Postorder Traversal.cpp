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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // array & binary tree
        // time complexity: O(n)
        // 16ms, beats 48.18%

        // method 1: using index
        // method 2 is much better!!
        return buildTree(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
    TreeNode* buildTree(vector<int>& inorder, int i_start, int i_end, vector<int>& postorder, int p_start, int p_end) {
        if(p_start >= p_end || i_start >= i_end) { return NULL; }
        
        int root_val = postorder[p_end - 1];
        auto pos = find(inorder.begin(), inorder.begin() + i_end, root_val);
        int dis = inorder.begin() + i_end - pos - 1;
        
        TreeNode* root = new TreeNode(root_val);
        root->left = buildTree(inorder, i_start, i_end - dis - 1, postorder, p_start, p_end - dis - 1);
        root->right = buildTree(inorder, i_end - dis, i_end, postorder, p_end - dis - 1, p_end - 1);
        return root;
    }
    
    // method 2: using iterator
    //directly using iterator could be faster
    /*
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.empty() || postorder.empty()) { return NULL; }
        return Helper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    TreeNode * Helper(vector<int>::iterator i_s, vector<int>::iterator i_e, vector<int>::iterator p_s, vector<int>::iterator p_e)
    {
        if (i_s == i_e) { return NULL; }
        int val = *(p_e - 1);
        vector<int>::iterator it = find(i_s, i_e, val);
        TreeNode* root = new TreeNode(val);
        TreeNode* left = Helper(i_s, it, p_s, p_s + (it - i_s));
        TreeNode* right = Helper(it+1, i_e, p_e - (i_e-it), p_e-1);
        root->left = left;
        root->right = right;
        return root;
    }
    */
    
    // method 3: using stack
    //using stack could even be faster
    /*
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        if(inorder.size() == 0 || postorder.size() == 0)
            return nullptr;
        TreeNode* root = new TreeNode(INT_MAX);
        int i = postorder.size() - 1; int j = inorder.size() - 1;
        stack<TreeNode*> s;
        //pp for parent pointer
        TreeNode* pp = nullptr; TreeNode* curr = root;
        s.push(root);
        
        while(j >= 0){
            //this means we meet the root in the middle and we're about to add the right subtree
            if(s.top()->val == inorder[j]){
                pp = s.top();
                s.pop();
                j--;
            }
            else if(pp != nullptr){
                //add the right child
                curr = new TreeNode(postorder[i]);
                pp->left = curr;
                pp = nullptr;
                s.push(curr);
                i--;
            }
            else{
                //add the left child(we would go as "left" as possible because of the property of preoder)
                curr = new TreeNode(postorder[i]);
                s.top()->right = curr;
                s.push(curr);
                i--;
            }
        }
        //because the root node is pushed twice
        return root->right;
    }
    */
};