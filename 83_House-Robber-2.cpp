/* 83. House Robber II
    Pattern: Circular DP

Problem Statement:
You are a professional robber planning to rob houses arranged in a circle.

Each house contains a certain amount of money.

The first and last houses are adjacent, so they cannot both be robbed.

Return the maximum amount of money you can rob without alerting the police.

Example 1:

Input:
nums = [2,3,2]

Output:
3

Explanation:
You cannot rob both the first and last house because they are adjacent.
The maximum amount is obtained by robbing only the second house.

Example 2:

Input:
nums = [1,2,3,1]

Output:
4

Explanation:
Possible optimal choices:

* Rob houses 1 and 3
* Total = 4

Core Concepts:
✅ Dynamic Programming
✅ Circular Array
✅ Space Optimization
✅ Decision Making

Main Logic:
Since first and last houses cannot both be robbed:

Case 1:
Rob from house 0 to n-2

Case 2:
Rob from house 1 to n-1

Answer:
max(case1, case2)

Important Insight:
Whenever a circular problem appears,
try converting it into two linear problems. */






class Solution {
public:

    int robLinear(vector<int>& nums, int start, int end)
    {
        int prev2 = 0;
        int prev1 = 0;

        for(int i = start; i <= end; i++)
        {
            int current =
                max(prev1,
                    nums[i] + prev2);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        return max(
            robLinear(nums,0,n-2),
            robLinear(nums,1,n-1)
        );
    }
};