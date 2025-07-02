/*
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

    Input: nums = [1,2,3,1]
    Output: true
*/

bool containsDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mpp;

    for (auto it : nums)
    {
        mpp[it]++;
        if (mpp[it] > 1)
            return true;
    }

    return false;
}