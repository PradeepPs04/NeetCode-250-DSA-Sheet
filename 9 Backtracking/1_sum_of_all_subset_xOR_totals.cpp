/*
    https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

    The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
        - For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.

    Given an array nums, return the sum of all XOR totals for every subset of nums.

    Note: Subsets with the same elements should be counted multiple times.

    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

    Input: nums = [1,3]
    Output: 6
*/

int solve(vector<int> &nums, int idx, int xorr)
{
    if (idx < 0)
        return xorr;

    int pick = solve(nums, idx - 1, xorr ^ nums[idx]);
    int not_pick = solve(nums, idx - 1, xorr);

    return pick + not_pick;
}

int subsetXORSum(vector<int> &nums)
{
    return solve(nums, nums.size() - 1, 0);
}