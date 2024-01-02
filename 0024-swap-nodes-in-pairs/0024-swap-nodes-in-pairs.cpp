/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* dummy = new ListNode(0); dummy->next = head; head = dummy;
        while(head and head->next and head->next->next) {
            ListNode* n1 = head->next; ListNode* n2 = n1->next;
            n1->next = n2->next;
            n2->next = n1;
            head->next = n2;
            head = n1;
        }
        return dummy->next;
    }
};