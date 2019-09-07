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
    // Design & stringstream
    // serial & deserial time complexity: O(n), space complexity: O(n)
    // 36ms, beats 79.85%
    
    // Actually using stringstream is time consuming, could use string parse

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeImpl(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeImpl(in);
    }

private:
    /* Helper function to transform binary tree to stringstream */
    void serializeImpl(TreeNode* root, ostringstream& out) {
        if(root) {
            out << root->val << " ";
            serializeImpl(root->left, out);
            serializeImpl(root->right, out);
        } else out << "# ";
    }
    
    /* Helper function to transform stringstream to binary tree */
    TreeNode* deserializeImpl(istringstream& in) {
        string cur;
        TreeNode* node;
        if(in >> cur) {
            if(cur == "#") return nullptr;
            else {
                node = new TreeNode(stoi(cur));
                node->left = deserializeImpl(in);
                node->right = deserializeImpl(in);
            }
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));