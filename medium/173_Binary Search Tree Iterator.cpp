/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {//Don't use BST characters, stupid solution
public:
    vector<int> leastNumber;
    BSTIterator(TreeNode *root) {
        readBST(root, leastNumber);
        sort(leastNumber.begin(),leastNumber.end());
    }
    
    void readBST(TreeNode* root, vector<int>& temp){
        if(root){
            temp.push_back(root->val);
            readBST(root->left,temp);
            readBST(root->right,temp);
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(leastNumber.empty())
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        int res=leastNumber[0];
        leastNumber.erase(leastNumber.begin(),leastNumber.begin()+1);
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


//make use of BST characters
class BSTIterator {
    TreeNode* cur;
    stack <TreeNode*> stack1;
public:
    BSTIterator(TreeNode *root) {
        cur = root;
        stack1.empty();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (stack1.size() != 0 || cur != nullptr) return true;
        return false;
    }

    /** @return the next smallest number */
    int next() {
        while (cur != nullptr) {
            stack1.push(cur);
            cur = cur->left;
        }
        cur = stack1.top();
        stack1.pop();
        int val = cur->val;
        cur = cur->right;
        return  val;
    }
};
