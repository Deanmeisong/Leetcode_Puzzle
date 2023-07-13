/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int d = 0, curr = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return d;
    }
    
    int diameter(TreeNode* root) {
        if(!root) return 0;
        int lh = diameter(root->left);
        int rh = diameter(root->right);
        curr = lh + rh;
        d = max(d, curr);
        return max(lh, rh) + 1;
    }
};