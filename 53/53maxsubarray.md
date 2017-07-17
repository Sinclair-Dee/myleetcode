## 53. Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
    For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
    the contiguous subarray [4,-1,2,1] has the largest sum = 6.

**题意是求数组中子数组的最大和:**

解法一：算法复杂度为O(n)
- 当部分序列和大于零的话就一直加下一个元素即可，并和当前最大值进行比较.
- 如果出现部分序列小于零的情况，那肯定就是从当前元素算起
- 转移方程就是:sum[i] = nums[i] + (sum[i - 1] > 0 ? sum[i - 1] : 0);
- 由于我们不需要保留sum状态，故可以优化空间复杂度为1，即`sum = nums[i] + (sum > 0 ? sum : 0);`。

解法二：算法复杂度为
-
-
