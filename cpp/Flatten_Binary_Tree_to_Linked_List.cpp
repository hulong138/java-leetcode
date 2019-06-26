/*
 Author:     Andy, nkuwjg@gmail.com
 Date:       Jan 28, 2015
 Problem:    Flatten Binary Tree to Linked List
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
 Notes:
 Given a binary tree, flatten it to a linked list in-place.
 For example,
 Given
     1
    / \
   2   5
  / \   \
 3   4   6
 The flattened tree should look like:
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 Hints:
 If you notice carefully in the flattened tree, each node's right child points to the next node
 of a pre-order traversal.

 Solution: Recursion. Return the last element of the flattened sub-tree.
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
	TreeNode *lastVisitedNode = NULL;
	void flatten(TreeNode *root) {
		if (root == NULL) return;

		TreeNode* right = root->right;
		if (lastVisitedNode != NULL)
		{
			lastVisitedNode->left = NULL;
			lastVisitedNode->right = root;
		}
		lastVisitedNode = root;
		flatten(root->left);
		flatten(right);
	}
};