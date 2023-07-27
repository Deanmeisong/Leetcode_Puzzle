/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    Node prev = null;
    Node head = null;
    Node tail = null;
    public Node treeToDoublyList(Node root) {
        if(root == null) return null;
        inorder(root);
        head.left = tail;
        tail.right = head;
        return head;
    }
    
    void inorder(Node root) {
        if(root == null) return;
        
        inorder(root.left);
        
        if(prev == null) {
            prev = root;
            head = root;
        } else {
            root.left = prev;
            prev.right = root;
            prev = root;
        }
        
        tail = root;
        inorder(root.right);
    }
}