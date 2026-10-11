/*
92. Gas Station
    Pattern: Greedy

Problem Statement:
There are n gas stations arranged in a circular route.

You are given two integer arrays:

* gas[i] = amount of gas available at station i
* cost[i] = gas required to travel from station i to the next station

You have an unlimited gas tank, but initially your tank is empty.

Return the starting gas station index from which you can travel around the entire circuit exactly once in the clockwise direction.

If it is impossible to complete the circuit, return -1.

Example 1:

Input:
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

Output:
3

Explanation:
Start at station 3.

Gas collected:
4 → 5 → 3 → 4 → 5

Costs:
1 → 2 → 3 → 4 → 3

You can complete the entire circuit starting from index 3.

Example 2:

Input:
gas  = [2,3,4]
cost = [3,4,3]

Output:
-1

Explanation:
The total amount of gas available is less than the total cost required,
so completing the circuit is impossible.

Core Concepts:
✅ Greedy Algorithm
✅ Circular Array
✅ Prefix / Running Sum
✅ Resetting Starting Position

Main Logic:
First check:

If total gas < total cost
→ return -1

Otherwise, a solution must exist.

Maintain:
currentGas

If currentGas becomes negative at station i:

* the current starting point cannot work
* none of the stations between the current start and i can work either
* set the next station as the new starting point

Important Insight:
The key greedy idea is:

👉 If you cannot reach station i + 1 from your current start,
there is no reason to try any station between the start and i.

This lets us solve the problem in O(n) time instead of trying every starting station.

━━━━━━━━━━━━━━━━━━

⚡ Greedy Era Begins:

Jump Game → Maximize Reach

Gas Station → Eliminate Impossible Starts

The greedy mindset:

👉 Make the strongest local decision
👉 Prove why discarded choices can never be optimal
👉 Move forward without looking back

That’s the real power of Greedy Algorithms. 🔥
*/


class Solution {
public:

    int canCompleteCircuit(
        vector<int>& gas,
        vector<int>& cost)
    {
        int totalGas = 0;
        int totalCost = 0;

        for(int i = 0; i < gas.size(); i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost)
            return -1;

        int start = 0;
        int currentGas = 0;

        for(int i = 0; i < gas.size(); i++)
        {
            currentGas += gas[i] - cost[i];

            if(currentGas < 0)
            {
                start = i + 1;
                currentGas = 0;
            }
        }

        return start;
    }
};