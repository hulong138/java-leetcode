/*
 Author:     Andy, nkuwjg@gmail.com
 Date:       Nov 18, 2014
 Problem:    Subsets
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/subsets/
 Notes:
 Given a set of distinct integers, S, return all possible subsets.
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,3], a solution is:
 [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
 ]

 Solution: 1. Updated Iterative solution.
           2. Updated Recursive solution.
 */
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > result;
        vector<int> output;
        if (S.size() == 0) return result;
        result.push_back(output); // the empty set
        sort(S.begin(), S.end());
        generateSub(S, 0, result, output);
    }
    void generateSub(
        vector<int> &s,
        int step,
        vector<vector<int> > &result,
        vector<int>& output)
    {
        for (int i = step; i < s.size(); i++ )
        {
            output.push_back(s[i]);
            result.push_back(output);
            if (i < s.size() - 1)
                generateSub(s, i + 1, result, output);
            output.pop_back();
        }
    }
};