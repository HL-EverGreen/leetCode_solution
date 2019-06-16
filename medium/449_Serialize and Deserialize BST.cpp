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
    // Binary tree & serialize
    // time complexity: both serialize and deserialize are both O(n).
    // space complexity: O(n)
    // 28ms, beats 93.42%
    
    // Main idea:
    // Convert all int into char[4] to save space.
    // Use DFS in both serialize and deserialize. Serialize is direct.
    // When deserialize, use min_val and max_val to determine whether current value fit this position.
    // If fits, adjust offset (pos). If not, return NULL, so this value could continue to find situable position.
    
    /*** This min_val and max_val idea is general in all BST problem!! ***/
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string stream;
        serial_dfs(root, stream);
        return stream;
    }
    

    /* Serialize tree using DFS */
    void serial_dfs(TreeNode* root, string& stream) {
        if(!root) { return; }

        /* Append each int using char format to save memory space */
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int));
        for(int i = 0; i < 4; i++) { stream.push_back(buf[i]); }

        serial_dfs(root->left, stream);
        serial_dfs(root->right, stream);
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserial_dfs(data, pos, INT_MIN, INT_MAX);
    }
    

    /* Construct BST using DFS */
    TreeNode* deserial_dfs(string& data, int& pos, int min_val, int max_val) {
        /* Check offset */
        if(pos >= data.size()) { return NULL; }
        
        /* Get value as int and check range */
        int value;
        memcpy(&value, &data[pos], sizeof(int));
        if(value < min_val || value > max_val) { return NULL; }
        
        /* Add this value node into BST and adjust offset */
        pos += sizeof(int);
        TreeNode *root = new TreeNode(value);
        root->left = deserial_dfs(data, pos, min_val, value);
        root->right = deserial_dfs(data, pos, value, max_val);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));