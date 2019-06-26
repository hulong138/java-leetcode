/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 25, 2014
 Problem:    Permutations
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/permutations/
 Notes:
 Given a collection of numbers, return all possible permutations.
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 Solution: dfs...
 */
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > coll;
        vector<int> solution;
        if (num.size() == 0) return coll;
        vector<int> visited(num.size(), 0);
        GeneratePermute(num, 0, visited, solution, coll);
        return coll;
    }

    void GeneratePermute(vector<int> & num, int step,
                         vector<int>& visited,
                         vector<int>& solution,
                         vector<vector<int> >& coll)
    {
        if (step == num.size())
        {
            coll.push_back(solution);
            return;
        }
        for (int i = 0; i < num.size(); i++)
        {
            // if this number already used, skip it
            if (visited[i] == 0)
            {
                visited[i] = 1;
                solution.push_back(num[i]);
                GeneratePermute(
                    num, step + 1, visited, solution, coll);
                solution.pop_back();
                visited[i] = 0;
            }
        }
    }
};