/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 20, 2014
 Problem:    Search in Rotated Sorted Array
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.

 Solution: Binary search. O(lgn)
 */
class Solution {
public:
    int search(vector<int>& A, int target) {
        int l = 0, r = A.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (A[m] == target) return m;
            if (A[m] >= A[l])
            {
                // target 5 in {4,5,6,2,3}
                if (A[l] <= target && target <= A[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            else
            {
                // target 2 in {5,0,1,2,3}
                if (A[m] < target && target < A[l])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
};