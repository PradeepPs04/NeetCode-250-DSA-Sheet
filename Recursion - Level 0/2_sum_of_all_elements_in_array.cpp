/*
    You are given an integer array arr[]. The task is to find the sum of it.
*/

int sum(vector<int> &arr, int idx)
{
    if (idx == 0)
        return arr[idx];
    return arr[idx] + sum(arr, idx - 1);
}

int arraySum(vector<int> &arr)
{
    return sum(arr, arr.size() - 1);
}