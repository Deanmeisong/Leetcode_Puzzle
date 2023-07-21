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
    int max = 0;
    public int longestConsecutive(TreeNode root) {
        if(root == null) return 0;
        helper(root, root.val, 0);
        return max;
    }
    
    void helper(TreeNode root, int target, int cur) {
        if(root == null) return;
        if(root.val == target + 1) ++cur;
        else cur = 1;
        max = Math.max(max, cur);
        helper(root.left, root.val, cur);
        helper(root.right, root.val, cur);
    }
}