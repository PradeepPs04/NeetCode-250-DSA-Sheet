/*
    https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

    Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

        -> [4,5,6,7,0,1,2] if it was rotated 4 times.
        -> [0,1,2,4,5,6,7] if it was rotated 7 times.
    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

    Given the sorted rotated array nums of unique elements, return the minimum element of this array.

    You must write an algorithm that runs in O(log n) time.


    Input: nums = [3,4,5,1,2]
    Output: 1
*/

int findMin(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;
    int mini = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        mini = min(mini, nums[mid]);

        // if smaller element to the right
        if (nums[mid] > nums[high])
            low = mid + 1;

        // if smaller element to the left
        else
            high = mid - 1;
    }

    return mini;
}