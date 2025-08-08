/*
    https://leetcode.com/problems/kth-largest-element-in-an-array/description/

    Given an integer array nums and an integer k, return the kth largest element in the array.

    Note that it is the kth largest element in the sorted order, not the kth distinct element.

    Can you solve it without sorting?


    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5
*/

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    for (int i = 0; i < k; i++)
        pq.push(nums[i]);

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] > pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }

    return pq.top();
}