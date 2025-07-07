/*
    Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

    A subarray is a contiguous non-empty sequence of elements within an array.


    Input: nums = [1,1,1], k = 2
    Output: 2

    Input: nums = [1,2,3], k = 3
    Output: 2
*/

int subarraySum(vector<int> &nums, int k)
{
    // if total sum till Xth index is sum
    // and we want subarray with sum k
    // there will be a subarray with sum k
    // if there was previously somewhere (sum - k) present

    int preSum = 0;
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int ans = 0;

    for (auto it : nums)
    {
        preSum += it;
        int req = preSum - k;
        ans += mpp[req];
        mpp[preSum]++;
    }

    return ans;
}