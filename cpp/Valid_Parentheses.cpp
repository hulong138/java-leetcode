/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true
Example 2:
Input: "()[]{}"
Output: true
Example 3:
Input: "(]"
Output: false
Example 4:
Input: "([)]"
Output: false
Example 5:
Input: "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> container;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                container.push(s[i]);
                continue;
            }
            if (container.size() == 0) return false;

            char top = container.top();
            container.pop();
            if (s[i] == ')' && top != '(') return false;
            if (s[i] == '}' && top != '{') return false;
            if (s[i] == ']' && top != '[') return false;
        }

        if (container.size() > 0) return false;
        return true;
    }
};