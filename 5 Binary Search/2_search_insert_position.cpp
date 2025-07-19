/*
    https://leetcode.com/problems/search-insert-position/description/

    Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

    You must write an algorithm with O(log n) runtime complexity.

    Input: nums = [1,3,5,6], target = 5
    Output: 2
*/

int searchInsert(vector<int> &nums, int target)
{
    if (target <= nums[0])
        return 0;
    if (target > nums[nums.size() - 1])
        return nums.size();
    if (target == nums[nums.size() - 1])
        return nums.size() - 1;

    int left = 1;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        // if target found in array
        if (nums[mid] == target)
            return mid;

        // if target should be placed at mid
        if (target < nums[mid] && target > nums[mid - 1])
            return mid;

        if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}