/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 13, 2014
 Problem:    Add Two Numbers
 Difficulty: easy
 Source:     https://oj.leetcode.com/problems/add-two-numbers/
 Notes:
 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

 Solution: dummy head...

 */
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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* result = new ListNode(-1);
		ListNode* pre = result;
		ListNode *pa = l1, *pb = l2;
		int carry = 0;
		while (pa != NULL || pb != NULL)
		{
			int av = pa == NULL ? 0 : pa->val;
			int bv = pb == NULL ? 0 : pb->val;
			ListNode* node = new ListNode((av + bv + carry) % 10);
			carry = (av + bv + carry) / 10;
			pre->next = node;
			pre = pre->next;
			pa = pa == NULL ? NULL : pa->next;
			pb = pb == NULL ? NULL : pb->next;
		}
		if (carry > 0)
			pre->next = new ListNode(1);
		pre = result->next;
		delete result;
		return pre;
	}
};