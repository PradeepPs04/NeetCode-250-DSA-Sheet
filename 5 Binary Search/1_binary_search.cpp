/*
    https://leetcode.com/problems/binary-search/

    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.

    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
*/

int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;

        if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}