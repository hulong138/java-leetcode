/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 13, 2014
 Problem:    Longest Palindromic Substring
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/longest-palindromic-substring/
 Notes:
 Given a string S, find the longest palindromic substring in S. 
 You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

 */

class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.size();
    int P[len][len];
    memset(P, 0, len * len * sizeof(int));
    int maxL = 0, start = 0, end = 0;
    for (int i = 0; i < s.size(); i++)
    {
      for (int j = 0; j < i; j++)
      {
        P[j][i] = (s[j] == s[i] && (i - j < 2 || P[j + 1][i - 1]));
        if (P[j][i] && maxL < (i - j + 1))
        {
          maxL = i - j + 1;
          start = j;
          end = i;
        }
      }
      P[i][i] = 1;
    }
    return s.substr(start, end - start + 1);
  }

};