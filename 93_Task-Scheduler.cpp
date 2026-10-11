/*
93. Task Scheduler
    Pattern: Heap + Greedy

Problem Statement:
You are given a character array tasks, where each character represents a task that needs to be executed.

You are also given an integer n, which represents the cooldown period between two executions of the same task.

In each unit of time, the CPU can either:

* Execute a task
* Remain idle

Return the minimum number of units of time required to complete all tasks.

Example 1:

Input:
tasks = [“A”,“A”,“A”,“B”,“B”,“B”]
n = 2

Output:
8

Explanation:

One possible schedule is:

A → B → idle → A → B → idle → A → B

Total time = 8

Example 2:

Input:
tasks = [“A”,“A”,“A”,“A”,“B”,“B”,“B”,“C”,“C”,“C”]
n = 2

Output:
10

Core Concepts:
✅ Greedy Algorithm
✅ Max Heap / Priority Queue
✅ Frequency Counting
✅ Scheduling
✅ Cooldown Management

Main Logic:

* Count the frequency of every task.
* Always prioritize the task with the highest remaining frequency.
* Use a max heap to select the most frequent available task.
* After executing a task, place it into a cooldown structure.
* Once its cooldown expires, add it back to the heap.

Important Insight:
The most frequent tasks are the hardest to schedule because they create the most cooldown gaps.

So the greedy strategy is:
👉 Handle the most frequent tasks first
👉 Fill gaps with other available tasks
👉 Use idle time only when necessary
*/

// https://youtu.be/Q9006pUcypI?si=oRKgS0iiU1lRovcN

public int LeastInterval(char[] tasks, int n)
{
    Dictionary<char, int> freq = new Dictionary<char, int>();

    foreach (char task in tasks)
    {
        if (!freq.ContainsKey(task))
            freq[task] = 0;

        freq[task]++;
    }

    PriorityQueue<int, int> maxHeap =
        new PriorityQueue<int, int>();

    foreach (int count in freq.Values)
    {
        // Negative priority makes it behave like a max heap
        maxHeap.Enqueue(count, -count);
    }

    Queue<(int count, int availableTime)> cooldown =
        new Queue<(int, int)>();

    int time = 0;

    while (maxHeap.Count > 0 || cooldown.Count > 0)
    {
        time++;

        // Move tasks whose cooldown is over
        if (cooldown.Count > 0 &&
            cooldown.Peek().availableTime == time)
        {
            var task = cooldown.Dequeue();

            maxHeap.Enqueue(task.count, -task.count);
        }

        if (maxHeap.Count > 0)
        {
            int count = maxHeap.Dequeue();

            count--;

            if (count > 0)
            {
                cooldown.Enqueue((count, time + n + 1));
            }
        }
    }

    return time;
}