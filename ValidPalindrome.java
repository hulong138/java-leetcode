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

public class  ValidPalindrome {
    static public int main( ){
        String s1 = new String();
        String s2 = "billryan";
        int s2Len = s2.length();
        s2.substring(4, 8); // return "ryan"
        StringBuilder s3 = new StringBuilder(s2.substring(4, 8));
        s3.append("bill");
        String s2New = s3.toString(); // return "ryanbill"
// convert String to char array
        char[] s2Char = s2.toCharArray();
// char at index 4
        char ch = s2.charAt(4); // return 'r'
// find index at first
        int index = s2.indexOf('r'); // return 4. if not found, return -1
    }
}
 public class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase().replaceAll("\\W", "");
        System.out.println(s);
        for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
            if (s.charAt(i) != s.charAt(j))
                return false;
        }
        return true;   
    }
}