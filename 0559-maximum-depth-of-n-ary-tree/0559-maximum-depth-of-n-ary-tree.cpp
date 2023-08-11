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

class Solution {
public:
    int maxDepth(Node* root) {
        
        return helper(root);
    }
    
    int helper(Node* root) {
        if(!root) return 0;
        int maxL = 0;
        for(Node* child : root->children) {
            int tmp = helper(child);
            if(tmp > maxL) {
                maxL = tmp;
            }
        }
        return 1 + maxL;
    }
};