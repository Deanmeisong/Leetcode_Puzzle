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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        function<TreeNode*(int, int)> dfs = [&](int left, int right) -> TreeNode*{
            if(left > right) return nullptr;
            int m = left + (right - left) / 2;
            TreeNode* root = new TreeNode(nums[m]);
            root->left = dfs(left, m - 1);
            root->right = dfs(m + 1, right);
            return root;
        };
        return dfs(0, n - 1);
    }
};