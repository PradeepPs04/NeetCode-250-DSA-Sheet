/*
    https://leetcode.com/problems/search-in-rotated-sorted-array/description/

    There is an integer array nums sorted in ascending order (with distinct values).

    Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

    Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

    You must write an algorithm with O(log n) runtime complexity.


    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
*/

int search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // check if target is found
        if (nums[mid] == target)
            return mid;

        // check which half is sorted left or right

        // check if left half is sorted
        if (nums[low] <= nums[mid])
        {
            // check if target is present in this left sorted part
            if (target >= nums[low] && target <= nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // if right half is sorted
        else
        {
            // check if target is present in this right sorted part
            if (target >= nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}