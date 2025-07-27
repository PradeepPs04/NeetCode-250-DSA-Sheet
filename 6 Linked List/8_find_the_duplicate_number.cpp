/*
    https://leetcode.com/problems/find-the-duplicate-number/description/

    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

    There is only one repeated number in nums, return this repeated number.

    You must solve the problem without modifying the array nums and using only constant extra space.


    Input: nums = [1,3,4,2,2]
    Output: 2
*/

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0]; // slow pointer
    int fast = nums[0]; // fast pointer

    // move slow pointer by 1 step and fast by 2 step
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // after they meet start slow on the first position
    slow = nums[0];
    while (slow != fast)
    {
        // move both 1 by 1 step
        slow = nums[slow];
        fast = nums[fast];
    }

    // where they meet that is the head of cycle (i.e. duplicate number)
    return slow; // or fast
}