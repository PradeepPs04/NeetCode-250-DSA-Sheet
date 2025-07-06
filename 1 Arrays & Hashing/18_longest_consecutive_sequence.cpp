/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

    You must write an algorithm that runs in O(n) time.


    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    Example 2:

    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9
*/

int longestConsecutive(vector<int> &nums)
{
    map<int, int> mpp;
    // store elements in hashmap
    for (auto it : nums)
        mpp[it] = 1;

    int maxi = 0;

    // iterate over hashmap instead of array
    for (auto it : mpp)
    {
        int val = it.first;
        // check the sequence from the lowest possible only
        if (mpp[val - 1])
            continue;

        int count = 0;
        while (mpp[val++])
            count++;

        maxi = max(maxi, count);
    }

    return maxi;
}