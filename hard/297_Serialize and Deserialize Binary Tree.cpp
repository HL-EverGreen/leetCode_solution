/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {  //actually using ostringstream & istringstream is very time-consuming, so we could also use queue
        ostringstream out;
        serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    
    void serialize(TreeNode* root, ostringstream& out){  //preorder traversal
        if(root){
            out<<root->val<<' ';
            serialize(root->left,out);
            serialize(root->right,out);
        }else{
            out<<"# ";
        }
    }
    
    TreeNode* deserialize(istringstream& in){
        string tmp;
        TreeNode* root;
        in>>tmp;
        if(tmp=="#") return nullptr;
        else{
            root=new TreeNode(stoi(tmp));
            root->left=deserialize(in);
            root->right=deserialize(in);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));