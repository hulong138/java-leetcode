/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 20, 2014
 Problem:    3Sum
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/3sum/
 Notes:
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 Find all unique triplets in the array which gives the sum of zero.
 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
 The solution set must not contain duplicate triplets.
 For example, given array S = {-1 0 1 2 -1 -4},
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)

 Solution: Simplify '3sum' to '2sum' O(n^2). http://en.wikipedia.org/wiki/3SUM
*/
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		std::sort(num.begin(), num.end());
		vector<vector<int>> result;
		for (int i = 0 ; i < num.size() ; i++ )
		{
			int target = 0 - num[i];
			int start = i + 1, end = num.size() - 1;
			while (start < end)
			{
				int sum = num[start] + num[end];
				if (sum == target)
				{
					vector<int> oneSolution;
					oneSolution.push_back(num[i]);
					oneSolution.push_back(num[start]);
					oneSolution.push_back(num[end]);
					result.push_back(oneSolution);
					start++;
					end--;
					while (start < num.size() && num[start] == num[start - 1]) start++;
					while (end > 0 && num[end] == num[end + 1]) end--;
				}

				if (sum < target)
				{
					start++;
				}

				if (sum > target)
				{
					end--;
				}
			}

			while (i < num.size() - 1 && num[i] == num[i + 1]) i++;
		}
		return result;
	}
};