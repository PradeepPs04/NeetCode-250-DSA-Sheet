/*
    https://leetcode.com/problems/single-threaded-cpu/description/

    You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.

    You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

        - If the CPU is idle and there are no available tasks to process, the CPU remains idle.
        - If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
        - Once a task is started, the CPU will process the entire task without stopping.
        - The CPU can finish a task then start a new one instantly.

    Return the order in which the CPU will process the tasks.

    Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
    Output: [0,2,3,1]
*/

vector<int> getOrder(vector<vector<int>> &tasks)
{
    // create new list to store tasks {enqueu time, processing time, id}
    vector<vector<int>> arr;
    for (int i = 0; i < tasks.size(); i++)
        arr.push_back({tasks[i][0], tasks[i][1], i});

    // sort processes according to arrival time
    sort(arr.begin(), arr.end());

    long long currTime = 1;

    int idx = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap {processing time, id}

    vector<int> ans;

    while (idx < arr.size() || !pq.empty())
    {
        // if no process available and current time is less than next process enqueu time
        if (idx < arr.size() && pq.empty() && arr[idx][0] > currTime)
            currTime = arr[idx][0];

        // add available processes to min heap
        while (idx < arr.size() && arr[idx][0] <= currTime)
        {
            pq.push({arr[idx][1], arr[idx][2]});
            idx++;
        }

        // get the available process having minimum processing time
        auto process = pq.top();
        pq.pop();

        ans.push_back(process.second);

        // increase current time
        currTime += process.first;
    }

    return ans;
}