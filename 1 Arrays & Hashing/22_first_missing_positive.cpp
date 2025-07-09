/*
    https://leetcode.com/problems/first-missing-positive/

    Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

    You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

    Input: nums = [1,2,0]
    Output: 3

    Input: nums = [3,4,-1,1]
    Output: 2

    Input: nums = [7,8,9,11,12]
    Output: 1
*/

int firstMissingPositive(vector<int> &nums)
{
    int n = nums.size();
    // elemninate 0's & -ve's
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= 0)
            nums[i] = n + 1;
    }

    // use array as hash
    for (int i = 0; i < nums.size(); i++)
    {
        // get the index of element
        int idx = abs(nums[i]) - 1;

        // if index is valid & not marked visited => mark it as visited
        if (idx >= 0 && idx < n && nums[idx] > 0)
            nums[idx] *= -1;
    }

    // traverse array to find the non-visited index
    for (int i = 0; i < nums.size(); i++)
    {
        // if unvisited index found
        if (nums[i] > 0)
            return i + 1;
    }

    // all elements from 1-n are present in the array
    return nums.size() + 1;
}