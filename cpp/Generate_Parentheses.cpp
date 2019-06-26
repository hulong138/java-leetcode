/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 20, 2014
 Problem:    Generate Parentheses
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/generate-parentheses/
 Notes:
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 For example, given n = 3, a solution set is:
 "((()))", "(()())", "(())()", "()(())", "()()()"

 Solution: Place n left '(' and n right ')'.
           Cannot place ')' if there are no enough matching '('.
 */
class Solution {
public:
	void CombinationPar(vector<string>& result, string& sample,
	                    int deep, int n, int leftNum, int rightNum)
	{
		if (deep == 2 * n)
		{
			result.push_back(sample);
			return;
		}
		if (leftNum < n)
		{
			sample.push_back('(');
			CombinationPar(
			    result, sample, deep + 1, n, leftNum + 1, rightNum);
			sample.resize(sample.size() - 1);
		}
		if (rightNum < leftNum)
		{
			sample.push_back(')');
			CombinationPar(
			    result, sample, deep + 1, n, leftNum, rightNum + 1);
			sample.resize(sample.size() - 1);
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string sample;
		if (n != 0)
			CombinationPar(result, sample, 0, n, 0, 0);
		return result;
	}
};