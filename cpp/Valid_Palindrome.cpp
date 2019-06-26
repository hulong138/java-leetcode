/*
 Author:     Andy, nkuwjg@gmail.com
 Date:       Jan 17, 2015
 Problem:    Valid Palindrome
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/valid-palindrome/
 Notes:
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.
 Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.
 For the purpose of this problem, we define empty string as valid palindrome.

 Solution: traverse from both side.
 */
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        std::transform(
            s.begin(), s.end(), s.begin(), ::tolower);
        while (start < end)
        {
            //filter non-alpha char
            while (start < end && !isAlpha(s[start])) start++;
            //filter non-alpha char
            while (start < end && !isAlpha(s[end])) end--;
            if (s[start] != s[end]) break;
            start++;
            end--;
        }
        if (start >= end)
            return true;
        else
            return false;
    }
    bool isAlpha(char c)
    {
        if (c >= 'a' && c <= 'z') return true;
        if (c >= '0' && c <= '9') return true;
        return false;
    }
};