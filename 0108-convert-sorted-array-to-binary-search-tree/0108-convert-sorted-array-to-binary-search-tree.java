/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int[] nums;
    public TreeNode sortedArrayToBST(int[] nums) {
        this.nums = nums;
        return dfs(0, nums.length - 1);
    }
    
    TreeNode dfs(int l, int r) {
        if(l > r) return null;
        int m = l + (r - l) / 2;
        TreeNode root = new TreeNode(this.nums[m]);
        root.left = dfs(l, m - 1);
        root.right = dfs(m + 1, r);
        return root;
    }
}