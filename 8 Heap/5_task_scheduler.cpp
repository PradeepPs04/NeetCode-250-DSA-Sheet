/*
    https://leetcode.com/problems/task-scheduler/description/

    You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

    Return the minimum number of CPU intervals required to complete all tasks.


    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
*/

int leastInterval(vector<char> &tasks, int n)
{
    // get frequency of each task
    vector<int> mpp(26, 0);
    for (auto ch : tasks)
        mpp[ch - 'A']++;

    // add all frequency to max heap
    priority_queue<int> pq; // max heap
    for (auto freq : mpp)
    {
        if (freq > 0)
            pq.push(freq);
    }

    int total_time = 0;

    while (!pq.empty())
    {
        vector<int> temp; // to store tasks that are done in N secomds

        // do n+1 tasks before doing the same task again
        for (int i = 1; i <= n + 1; i++)
        {
            if (!pq.empty())
            {
                int freq = pq.top();
                pq.pop();
                freq--; // one unit of the task is done
                temp.push_back(freq);
            }
        }

        // if any of task still having unit left then add it to heap
        for (auto it : temp)
        {
            if (it > 0)
                pq.push(it);
        }

        // if there are no more task in heap
        if (pq.empty())
            total_time += temp.size();
        else
            total_time += n + 1;
    }

    return total_time;
}