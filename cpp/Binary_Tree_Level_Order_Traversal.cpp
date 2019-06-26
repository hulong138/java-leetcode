/*
 Author:     Andy, nkuwjg@gmail.com
 Date:       Dec 12, 2014
 Problem:    Binary Tree Level Order Traversal
 Difficulty: easy
 Source:     https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
 Notes:
 Given a binary tree, return the level order traversal of its nodes' values. 
 (ie, from left to right, level by level).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its level order traversal as:
 [
  [3],
  [9,20],
  [15,7]
 ]
 
 Solution: 1. Use queue. In order to seperate the levels, use 'NULL' as the end indicator of one level.
           2. DFS.
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
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > result;
		if (root == NULL) return result;
		queue<TreeNode*> nodeQ;
		nodeQ.push(root);
		int nextLevelCnt = 0, currentLevelCnt = 1;
		vector<int> layer;
		int visitedCnt = 0;
		while (nodeQ.size() != 0)
		{
			TreeNode* node = nodeQ.front();
			nodeQ.pop();
			visitedCnt++;
			layer.push_back(node->val);
			if (node->left != NULL)
			{
				nodeQ.push(node->left);
				nextLevelCnt++;
			}
			if (node->right != NULL)
			{
				nodeQ.push(node->right);
				nextLevelCnt++;
			}
			if (visitedCnt == currentLevelCnt)
			{
				visitedCnt = 0;
				currentLevelCnt = nextLevelCnt;
				nextLevelCnt = 0;
				result.push_back(layer);
				layer.clear();
			}
		}
		return result;
	}
};