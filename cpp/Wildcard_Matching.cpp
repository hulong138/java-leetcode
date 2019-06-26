/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 20, 2014
 Problem:    Wildcard Matching
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/wildcard-matching/
 Notes:
 Implement wildcard pattern matching with support for '?' and '*'.
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 The matching should cover the entire input string (not partial).
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 Some examples:
 isMatch("aa","a") ? false
 isMatch("aa","aa") ? true
 isMatch("aaa","aa") ? false
 isMatch("aa", "*") ? true
 isMatch("aa", "a*") ? true
 isMatch("ab", "?*") ? true
 isMatch("aab", "c*a*b") ? false

 Solution: 1. if s[i]  == p[j] || p[j] == '?', ++i and ++j.
                ii, jj, record the positon of '*' in s and p, ++j and go on.
                if not match, go back to star, i = ++ii;
*/
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        bool star = false;
        const char *str, *ptr;
        for (str = s, ptr = p; *str != '\0'; str++, ptr++)
        {
            switch (*ptr)
            {
                case '?':
                    break;
                case '*':
                    star = true;
                    s = str, p = ptr;
                    while (*p == '*')
                        p++;
                    if (*p == '\0') // if nil after '*', return true
                        return true;
                    str = s - 1;
                    ptr = p - 1;
                    break;
                default:
                {
                    if (*str != *ptr)
                    {
                        // if no '*' in front, match failed
                        if (!star)
                            return false;
                        s++;
                        str = s - 1;
                        ptr = p - 1;
                    }
                }
            }
        }
        while (*ptr == '*')
            ptr++;
        return (*ptr == '\0');
    }
};