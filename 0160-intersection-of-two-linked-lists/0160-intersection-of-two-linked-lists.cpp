/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        ListNode* p1 = a; ListNode* p2 = b;
        while(p1 != p2) {
            p1 = p1 ? p1->next : b;
            p2 = p2 ? p2->next : a;
        }
        return p1;
    }
};