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
    int ans = 0;
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        helper(root, root->val, 0);
        return ans;
    }
    
    void helper(TreeNode* root, int target, int cur) {
        if(!root) return;
        if(target + 1 == root->val) ++cur;
        else cur = 1;
        
        ans = max(ans, cur);
        helper(root->left, root->val, cur);
        helper(root->right, root->val, cur);
    }
};