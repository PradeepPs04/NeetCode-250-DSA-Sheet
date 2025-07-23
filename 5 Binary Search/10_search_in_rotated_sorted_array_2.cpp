/*
    https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

    There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

    Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

    Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

    You must decrease the overall operation steps as much as possible.


    Input: nums = [2,5,6,0,0,1,2], target = 0
    Output: true
*/

bool search(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // check if target found
        if (nums[mid] == target)
            return true;

        // trim down search space, if we can't determine sorted half
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
            continue;
        }

        // check if left half is sorted
        if (nums[low] <= nums[mid])
        {
            // if target is in left sorted half then eliminate right half
            if (target >= nums[low] && target <= nums[mid])
                high = mid - 1;
            // else eliminate left sorted half
            else
                low = mid + 1;
        }
        // if right half is sorted
        else
        {
            // if target is in right sorted half then eliminate left half
            if (target >= nums[mid] && target <= nums[high])
                low = mid + 1;
            // else eliminate right sorted half
            else
                high = mid - 1;
        }
    }

    // if target not found
    return false;
}