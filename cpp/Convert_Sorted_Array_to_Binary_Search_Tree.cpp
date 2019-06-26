/*
 Author:     Andy, nkuwjg@gmail.com
 Date:       Jan 29, 2015
 Problem:    Convert Sorted Array to Binary Search Tree
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 Notes:
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

 Solution: Recursion. 1. preorder
                      2. inorder
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return BuildTree(num, 0, num.size() - 1);
	}
	
	TreeNode *BuildTree(vector<int> &num, int start, int end)
	{
		if (start > end) return NULL;
		if (start == end) return new TreeNode(num[start]);
		int mid = (start + end) / 2;
		TreeNode *node = new TreeNode(num[mid]);
		node->left = BuildTree(num, start, mid - 1);
		node->right = BuildTree(num, mid + 1, end);
		return node;
	}
};