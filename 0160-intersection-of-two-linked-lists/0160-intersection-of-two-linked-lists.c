/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *A, struct ListNode *B) {
    struct ListNode* a = A; struct ListNode* b = B;
    while(a != b) {
        a = a ? a->next : B;
        b = b ? b->next: A;
    }
    return a;
}