/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function bstToGst(root: TreeNode | null): TreeNode | null {
    let sum = 0;
    var dfs = function(node) {
        if(node != null) {
            dfs(node.right);
            sum += node.val;
            node.val = sum;
            dfs(node.left);
        }
        return node;
    }
    dfs(root);
    return root;
};