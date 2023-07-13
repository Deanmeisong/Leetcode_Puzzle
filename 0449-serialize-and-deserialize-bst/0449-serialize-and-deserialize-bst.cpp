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
    string serialize(TreeNode* root) {
        string s;
        serialize(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return deserialize(data, pos, INT_MIN, INT_MAX);
    }
    
private:
    void serialize(TreeNode* root, string& s) {
        if(!root) return;
        s.append(reinterpret_cast<const char*>(&root->val), sizeof(root->val));
        serialize(root->left, s);
        serialize(root->right, s);
    }
    
    TreeNode* deserialize(string& s, int& pos, int left, int right) {
        if(pos >= s.size()) return nullptr;
        int val = *reinterpret_cast<int*>(s.data() + pos);
        if(val > right or val < left) return nullptr;
        pos += sizeof(val);
        TreeNode* root = new TreeNode(val);
        root->left = deserialize(s, pos, left, val);
        root->right = deserialize(s, pos, val, right);
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;