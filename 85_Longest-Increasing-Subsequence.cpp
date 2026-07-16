/* 85. Longest Increasing Subsequence (LIS)
    Pattern: DP + Binary Search

Problem Statement:
Given an integer array nums,
return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input:
nums = [10,9,2,5,3,7,101,18]

Output:
4

Explanation:
The longest increasing subsequence is:
[2,3,7,101]

Length = 4

Example 2:

Input:
nums = [0,1,0,3,2,3]

Output:
4

Example 3:

Input:
nums = [7,7,7,7,7]

Output:
1

Core Concepts:
✅ Dynamic Programming
✅ Binary Search Optimization
✅ Subsequences
✅ State Optimization

Main Logic:
DP Approach:
For every element,
find the longest increasing subsequence ending at that element.

Transition:

dp[i] = 1 + max(dp[j])

where:
j < i and nums[j] < nums[i]

Optimized Approach:
Maintain a list of smallest possible ending values for increasing subsequences of different lengths.
Use Binary Search to update this list.

Important Insight:
Subsequence ≠ Subarray

Subsequence:
Elements maintain order but need not be contiguous. */







class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> dp(n,1);

        int ans = 1;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] =
                        max(dp[i],
                            dp[j]+1);
                }
            }

            ans=max(ans,dp[i]);
        }

        return ans;
    }
};