/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 25, 2014
 Problem:    Maximum Subarray
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/maximum-subarray/

 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] has the largest sum = 6.

 Solution: dp.
 */
class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int maxV = INT_MIN;
    return maxArray(nums, 0, nums.size() - 1, maxV);
  }

  int maxArray(vector<int>& A, int left, int right, int& maxV)
  {
    if (left > right)
      return INT_MIN;
    int mid = (left + right) / 2;
    int lmax = maxArray(A, left, mid - 1, maxV);
    int rmax = maxArray(A, mid + 1, right, maxV);
    maxV = max(maxV, lmax);
    maxV = max(maxV, rmax);
    int sum = 0, mlmax = 0;
    for (int i = mid - 1; i >= left; i--)
    {
      sum += A[i];
      if (sum > mlmax)
        mlmax = sum;
    }
    sum = 0; int mrmax = 0;
    for (int i = mid + 1; i <= right; i++)
    {
      sum += A[i];
      if (sum > mrmax)
        mrmax = sum;
    }
    maxV = max(maxV, mlmax + mrmax + A[mid]);
    return maxV;
  }
};