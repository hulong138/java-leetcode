/**
 21. Merge Two Sorted Lists
Easy

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4*
 
 
 Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

        ListNode* head = new ListNode(-1);

        ListNode* cur = head, *first = l1, *second = l2;

        while (first != NULL || second != NULL)
        {
            int lval = first == NULL ? INT_MAX : first->val;
            int rval = second == NULL ? INT_MAX : second->val;
            if (lval < rval)
            {
                cur->next = first;
                cur = first;
                first = first == NULL ? NULL : first->next;
            }
            else
            {
                cur->next = second;
                cur = second;
                second = second == NULL ? NULL : second->next;
            }
        }

        ListNode* newhead = head->next;
        delete head;
        return newhead;
    }
};