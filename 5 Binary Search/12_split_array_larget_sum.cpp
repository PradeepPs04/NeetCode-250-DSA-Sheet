/*
    https://leetcode.com/problems/split-array-largest-sum/

    Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

    Return the minimized largest sum of the split.

    A subarray is a contiguous part of the array.


    Input: nums = [7,2,5,10,8], k = 2
    Output: 18
*/

bool valid(vector<int> &nums, int k, int allowed)
{
    int sum = 0;
    for (auto it : nums)
    {
        sum += it;

        if (sum >= allowed)
        {
            if (sum > allowed)
                sum = it;
            else
                sum = 0;

            k--;
        }
    }

    if (sum > 0)
        k--;

    if (k < 0)
        return false;
    return true;
}

int splitArray(vector<int> &nums, int k)
{
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (valid(nums, k, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}