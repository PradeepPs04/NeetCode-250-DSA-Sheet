/*
    https://leetcode.com/problems/concatenation-of-array/

    Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

    Specifically, ans is the concatenation of two nums arrays.

    Return the array ans.

    Input: nums = [1,2,1]
    Output: [1,2,1,1,2,1]
*/

vector<int> getConcatenation(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
        nums.push_back(nums[i]);
    return nums;
}