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
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, &ans);
        return ans;
    }
private:
    tuple<int,int,int,bool> dfs(TreeNode* root, int* ans) {
        if(!root) return {INT_MAX, INT_MIN, 0, true};
        auto [ll, lh, ls, li] = dfs(root->left, ans);
        auto [rl, rh, rs, ri] = dfs(root->right, ans);
        bool valid = li && ri && root->val > lh && root->val < rl;
        int sum = valid ? ls + rs + root->val : -1;
        *ans = max(*ans, sum);
        return {min(ll, root->val), max(rh, root->val), sum, valid};
    }
};