/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

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
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(root == nullptr) return nullptr;
        TreeNode* newRoot = new TreeNode(root->val);
        vector<Node*> children = root->children;
        if(children.size() == 0) return newRoot;
        else {
            newRoot->left = encode(children[0]);
            if(children.size() == 1) return newRoot;

            TreeNode* cur = newRoot->left;
            for(int i = 1; i < children.size(); ++i) {
                cur->right = encode(children[i]);
                cur = cur->right;
            }

            return newRoot;
        }

    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if(root == nullptr) return nullptr;
        Node* newRoot = new Node(root->val);
        
        if(root->left == nullptr) return newRoot;
        else {
            TreeNode* cur = root->left;
            while(cur != nullptr) {
                newRoot->children.push_back(decode(cur));
                cur = cur->right;
            }
            return newRoot;
        }

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));